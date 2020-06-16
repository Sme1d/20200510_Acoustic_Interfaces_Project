#include "core_pins.h"
#include "AudioStream.h"

class AudioAnalyzeEnvelopeFollower : public AudioStream
{
public:
        AudioAnalyzeEnvelopeFollower() :
          AudioStream(1, inputQueueArray)
          {
            _new_output = false;
            _decay = 0.95;
          };
          
        virtual void update(void);
        float read();
        bool available();
        void setDecayRate(float decay);
        
private:
        audio_block_t *inputQueueArray[1];
        int _abs;
        bool _new_output;
        int _peak;
        float _decay;
};
