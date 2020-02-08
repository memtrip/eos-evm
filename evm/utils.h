class Utils {
  public:
    static void printOpcode(unsigned char value);
    static void printTier(unsigned char value);
    static void printOpcodeHex(unsigned char value);
    static void printInstruction(unsigned int value);
    static void printInstructionList();
    static void hex2bin(const std::string& hex, char* bytes);
};