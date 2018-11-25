#include "ops/midi.h"

#include "helpers.h"
#include "ii.h"
#include "teletype.h"
#include "teletype_io.h"
#include "telex.h"


static void op_MIDI_CC_set(const void *data, scene_state_t *ss, exec_state_t *es,
    command_state_t *cs);


const tele_op_t op_MIDI_CC = MAKE_SET_OP(MIDI.CC, op_MIDI_CC_set, 1, true);


static void op_MIDI_CC_set(const void *NOTUSED(data),
                           scene_state_t *NOTUSED(ss), exec_state_t *NOTUSED(es), command_state_t *cs)
{
    int16_t input = cs_pop(cs);
    uint8_t d[] = { MIDI_CC, input };
    tele_ii_tx(MIDI_ADDR, d, 2);
}
