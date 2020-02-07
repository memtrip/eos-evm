class VM {
  public:
    void execute_stack(char byte_code[], std::set<unsigned int> jumps);
};