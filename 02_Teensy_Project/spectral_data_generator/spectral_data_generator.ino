#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "EnvelopeFollower.h"

// GUItool: begin automatically generated code
AudioInputI2S            in;           //xy=416.0833282470703,337.0833282470703
AudioOutputI2S           out;           //xy=740.0833282470703,336.0833282470703
AudioAnalyzeFFT256       fft;       //xy=539.0833282470703,198.0833282470703
AudioConnection          patchCord1(in, 0, out, 0);
AudioConnection          patchCord2(in, 1, out, 1);
AudioConnection          patchCord3(in, 0, fft, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=579.0833129882812,432.08331298828125

// GUItool: end automatically generated code

AudioAnalyzeEnvelopeFollower envelopeFollower;
AudioConnection          patchCord4(in, 0, envelopeFollower, 0);

float _threshld = -30;
bool _gatherFFT = false;
float _fftSUM[4];
int _fftCount = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  AudioMemory(8);
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(AUDIO_INPUT_MIC);
  sgtl5000_1.micGain(34);
  sgtl5000_1.volume(0.8);
  envelopeFollower.setDecayRate(0.95);

  _fftSUM[0] = 0;
  _fftSUM[1] = 0;
  _fftSUM[2] = 0;
  _fftSUM[3] = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(envelopeFollower.available()) 
  {
    float amplitude = todb(envelopeFollower.read()+0.0000000001);
    if (amplitude > _threshld)
    {
      _gatherFFT = true;
      Serial.print("Envelope Loudness: ");
      Serial.print(amplitude);
      Serial.println();
    }
    else _gatherFFT=false;
  }

  if (fft.available() && _gatherFFT) {
     _fftSUM[0]+= fft.read( 0, 31);
     _fftSUM[1]+= fft.read(32, 63);
     _fftSUM[2]+= fft.read(64, 95);
     _fftSUM[3]+= fft.read(96,127);
     _fftCount++;
  }
  if(!_gatherFFT && _fftCount>0)
  {
    Serial.print("Bass: ");
    Serial.print(todb(_fftSUM[0]/_fftCount+0.000000000001));
    Serial.print(" | Low Mid: ");
    Serial.print(todb(_fftSUM[1]/_fftCount+0.000000000001));
    Serial.print(" | High Mid: ");
    Serial.print(todb(_fftSUM[2]/_fftCount+0.000000000001));
    Serial.print(" | Treble: ");
    Serial.print(todb(_fftSUM[3]/_fftCount+0.000000000001));
    Serial.println();
    _fftSUM[0] = 0;
    _fftSUM[1] = 0;
    _fftSUM[2] = 0;
    _fftSUM[3] = 0;
    _fftCount = 0;
  }
}

float todb(float a)
{
  return 20*log10(a);
}
