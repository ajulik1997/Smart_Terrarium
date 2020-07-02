/* ===== DEFINE PIN NUMBERS ===== */

const byte AMUX_OUT = A0;

/* ===== SETUP GLOBAL VARS ===== */

CD74HC4067 amux(3, 4, 5, 6);

/* ===== HELPER FUNCTIONS FOR MAIN ===== */

int read_device(byte device_id) {
  amux.channel(device_id);
  return analogRead(AMUX_OUT)
}
