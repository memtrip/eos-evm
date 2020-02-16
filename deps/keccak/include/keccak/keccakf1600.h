class Keccakf1600 {
  public:
    static uint64_t rol(uint64_t x, unsigned s);
    static const uint64_t round_constants[24];
    static void keccakf1600(uint64_t state[25]);
};