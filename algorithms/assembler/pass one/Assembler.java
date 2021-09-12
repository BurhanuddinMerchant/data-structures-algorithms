import java.io.*;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Vector;

class Assembler {
    HashMap<String, String> ISTAB = new HashMap<>();
    HashMap<String, String> ADTAB = new HashMap<>();
    HashMap<String, String> DSTAB = new HashMap<>();
    HashMap<String, String> REGISTER = new HashMap<>();

    // Output tables
    Vector<Vector<String>> SYMBTAB = new Vector<>();
    Vector<Vector<String>> LITTAB = new Vector<>();
    Vector<Vector<String>> POOLTAB = new Vector<>();
    Vector<Vector<String>> OPTAB = new Vector<>();
    Vector<Vector<String>> IC = new Vector<>();

    // program data
    Vector<Vector<String>> input = new Vector<>();
    Vector<Vector<String>> output = new Vector<>();
    Integer LocationCounter;

    Assembler(String filename) {
        initializeISTAB();
        initializeADTAB();
        initializeDSTAB();
        initializeREGISTER();
        this.LocationCounter = 0;
        initializeInputVectorFromInputFile(filename);
    }

    private void initializeISTAB() {
        // IS
        this.ISTAB.put("STOP", "00");
        this.ISTAB.put("ADD", "01");
        this.ISTAB.put("SUB", "02");
        this.ISTAB.put("MULT", "03");
        this.ISTAB.put("MOVER", "04");
        this.ISTAB.put("MOVEM", "05");
        this.ISTAB.put("COMP", "06");
        this.ISTAB.put("BC", "07");
        this.ISTAB.put("DIV", "08");
        this.ISTAB.put("READ", "09");
        this.ISTAB.put("PRINT", "10");
    }

    private void initializeADTAB() {
        // AD
        this.ADTAB.put("START", "01");
        this.ADTAB.put("END", "02");
        this.ADTAB.put("ORIGIN", "03");
        this.ADTAB.put("EQU", "04");
        this.ADTAB.put("LTORG", "05");

    }

    private void initializeDSTAB() {
        // DS
        this.DSTAB.put("DC", "01");
        this.DSTAB.put("DS", "02");

    }

    private void initializeREGISTER() {
        this.REGISTER.put("AREG", "01");
        this.REGISTER.put("BREG", "02");
        this.REGISTER.put("CREG", "03");
        this.REGISTER.put("DREG", "04");

    }

    private Vector<String> stringToVector(String instruction) {
        Vector<String> instruction_vector = new Vector<>();
        String inst = "";
        for (int i = 0; i < instruction.length(); i++) {
            if (instruction.charAt(i) == ' ') {
                if (inst == "")
                    continue;
                else {
                    instruction_vector.add(inst);
                    inst = "";
                }
            } else {
                inst += instruction.charAt(i);

            }
        }
        if (inst != "") {
            instruction_vector.add(inst);
        }
        return instruction_vector;
    }

    public void printVector(Vector<Vector<String>> v) {
        for (int i = 0; i < v.size(); i++) {
            System.out.println("Line " + (i + 1) + " " + v.get(i));
        }
    }

    public boolean isNumeric(String str) {
        try {
            Double.parseDouble(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    private Integer getCalculatedLocation(String s) {
        Integer res = 0;
        Vector<String> string_vector = new Vector<>();
        String str = "";
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '+' || s.charAt(i) == '-') {
                string_vector.add(str);
                string_vector.add(s.charAt(i) + "");
                str = "";
            } else {
                str += s.charAt(i);
            }
        }
        if (str != "") {
            string_vector.add(str);
        }
        if (string_vector.size() == 1) {
            for (int i = 0; i < this.SYMBTAB.size(); i++) {
                if (this.SYMBTAB.get(i).get(0) == string_vector.get(0)) {
                    return Integer.parseInt(this.SYMBTAB.get(i).get(1));
                }
            }
        } else {
            Integer op1 = 0, op2 = 0;
            if (isNumeric(string_vector.get(0))) {
                op1 = Integer.parseInt(string_vector.get(0));
            } else {
                for (int i = 0; i < this.SYMBTAB.size(); i++) {
                    if (this.SYMBTAB.get(i).get(0) == string_vector.get(0)) {
                        op1 = Integer.parseInt(this.SYMBTAB.get(i).get(1));
                    }
                }
            }
            if (isNumeric(string_vector.get(2))) {
                op2 = Integer.parseInt(string_vector.get(2));
            } else {
                for (int i = 0; i < this.SYMBTAB.size(); i++) {
                    if (this.SYMBTAB.get(i).get(0) == string_vector.get(2)) {
                        op2 = Integer.parseInt(this.SYMBTAB.get(i).get(1));
                    }
                }
            }
            if (string_vector.get(1) == "+") {
                return op1 + op2;
            } else {
                return op1 - op2;
            }
        }
        return res;
    }

    private void initiatePassOne() {
        for (Vector<String> instruction_line : this.input) {
            String LABEL = instruction_line.get(0);
            String OPCODE = instruction_line.get(1);
            String OPERAND = instruction_line.get(2);
            Vector<String> ic_vector = new Vector<>();
            if (!LABEL.equals("*")) {
                Vector<String> v = new Vector<>();
                boolean exists = false;
                for (Vector<String> s : this.SYMBTAB) {
                    if (s.get(0) == LABEL) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) {
                    System.out.println("Label : " + LABEL);
                    ;
                    v.add(LABEL);
                    v.add(LocationCounter.toString());
                    this.SYMBTAB.add(v);
                }
            }
            if (ISTAB.containsKey(OPCODE)) {
                // if imparitive
                ic_vector.add("(IS," + ISTAB.get(OPCODE) + ")");
                if (OPERAND.contains("=") || OPERAND.contains("\'")) {
                    // add literal to LITTAB
                    String[] s = OPERAND.split(",");
                    ic_vector.add("(RG," + this.REGISTER.get(s[0]) + ",)");
                    Vector<String> lt = new Vector<>();
                    lt.add(s[1]);
                    lt.add(LocationCounter.toString());
                    this.LITTAB.add(lt);
                    Integer lindx = (this.LITTAB.size() - 1);
                    ic_vector.add("(L," + lindx.toString() + ")");
                } else {
                    // add symbol to SYMBTAB
                    String[] s = OPERAND.split(",");
                    ic_vector.add("(RG," + this.REGISTER.get(s[0]) + ",)");
                    Vector<String> st = new Vector<>();
                    st.add(s[1]);
                    st.add(LocationCounter.toString());
                    this.SYMBTAB.add(st);
                    Integer lindx = (this.SYMBTAB.size() - 1);
                    ic_vector.add("(S," + lindx.toString() + ")");
                }
                this.LocationCounter += 1;
            } else if (ADTAB.containsKey(OPCODE)) {
                // if assembler directive
                if (OPCODE.equals("START")) {
                    this.LocationCounter = Integer.parseInt(OPERAND);
                } else if (OPCODE.equals("ORIGIN")) {
                    if (isNumeric(OPERAND)) {
                        this.LocationCounter = Integer.parseInt(OPERAND);
                    } else {
                        this.LocationCounter = getCalculatedLocation(OPERAND);
                    }
                } else if (OPCODE.equals("EQU")) {
                    Integer val;
                    if (isNumeric(OPERAND)) {
                        val = Integer.parseInt(OPERAND);
                    } else {
                        val = getCalculatedLocation(OPERAND);
                    }
                    for (int i = 0; i < this.SYMBTAB.size(); i++) {
                        if (this.SYMBTAB.get(i).get(0) == LABEL) {
                            this.SYMBTAB.get(i).set(1, val.toString());
                            break;
                        }
                    }
                } else if (OPCODE.equals("END")) {
                    ic_vector.add("(AD," + ADTAB.get(OPCODE));
                    break;
                }
                ic_vector.add("(AD," + ADTAB.get(OPCODE) + ")");
                if (isNumeric(OPERAND)) {
                    ic_vector.add("(C," + OPERAND + ")");
                }
            } else {
                // if declarative
                for (int i = 0; i < this.SYMBTAB.size(); i++) {
                    if (this.SYMBTAB.get(i).get(0) == LABEL) {
                        System.out.println("Again " + LABEL);
                        Vector<String> v = new Vector<>();
                        v.add(this.SYMBTAB.get(i).get(0));
                        v.add(LocationCounter.toString());
                        this.SYMBTAB.set(i, v);
                        break;
                    }
                }
                this.LocationCounter += Integer.parseInt(OPERAND);
                ic_vector.add("(DL," + DSTAB.get(OPCODE) + ")");
            }
            this.IC.add(ic_vector);
        }
    }

    private void initializeInputVectorFromInputFile(String fileName) {
        try {
            File inputFile = new File(fileName);
            Scanner dataReader = new Scanner(inputFile);
            while (dataReader.hasNextLine()) {
                String instruction = dataReader.nextLine();
                this.input.add(stringToVector(instruction));
            }
            dataReader.close();
        } catch (FileNotFoundException exception) {
            System.out.println("Unexcpected error occurred!");
            exception.printStackTrace();
        }
        initiatePassOne();
        // printVector(this.input);
        System.out.println("Literal Table \n");
        printVector(this.LITTAB);
        System.out.println("OP Table \n");
        printVector(this.OPTAB);
        System.out.println("Symb Table \n");
        printVector(this.SYMBTAB);
        System.out.println("IC Table \n");
        printVector(this.IC);
        System.out.println("LC : " + this.LocationCounter);
    }

}
