class Keccakf800 {
  public:
    static uint32_t rol(uint32_t x, unsigned s);
    static const uint32_t round_constants[22];
    static void keccakf800(uint32_t state[25]);
};