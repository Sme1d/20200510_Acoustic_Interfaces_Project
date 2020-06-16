#include "EnvelopeFollower.h"
#include <stdlib.h>

void AudioAnalyzeEnvelopeFollower::update(){

  audio_block_t *block = receiveReadOnly(0);
  if( !block) return;

  for (int i=0; i < AUDIO_BLOCK_SAMPLES; i++)
  {
    _abs = abs(block->data[i]);
    if(_abs > _peak) 
    {
      _peak = _abs;
    }
  }
  _peak = _peak * _decay;
  _new_output = true;
  release(block);
}

float AudioAnalyzeEnvelopeFollower::read()
{
  return (float)_peak / 32767;
}

bool AudioAnalyzeEnvelopeFollower::available()
{
  __disable_irq();
  bool flag = _new_output;
  if (flag) _new_output = false;
  __enable_irq();
  return flag;
}

void AudioAnalyzeEnvelopeFollower::setDecayRate(float decay)
{
  _decay = decay;
}
