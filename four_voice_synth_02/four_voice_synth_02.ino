/* An attempt at a four-voice, polyphonic synth using the Teensy Audio library.

   Features:
   two operators per voice, plus noise
   sinewave LFO
   ADSR envelopes for VCA, VCF, and noise VCA
   
*/

// TODO:
// Tremolo
// Vibrato
// noise EG CCs
 
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
// teensy 3.x midi pins
// rx 0
// tx 1
#include <MIDI.h>
// Bounce button library
// from here git clone https://github.com/thomasfredericks/Bounce-Arduino-Wiring.git
#include <Bounce2.h>
// MIDI channel set button 
// for using eeprom
#include <EEPROM.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise2;         //xy=63.33332824707031,316.6666736602783
AudioSynthNoiseWhite     noise1;         //xy=66.66664123535156,187.7777919769287
AudioSynthWaveform       voice2a;      //xy=70,244.44444444444443
AudioSynthWaveform       voice2b;      //xy=71.11109161376953,281.11111068725586
AudioSynthNoiseWhite     noise4;         //xy=71.11111111111111,534.4444444444445
AudioSynthWaveform       voice1b;      //xy=74.4444351196289,148.88888931274414
AudioSynthWaveform       voice4a;      //xy=73.33333333333333,460
AudioSynthWaveform       voice4b;      //xy=73.33331298828125,499.9999713897705
AudioSynthWaveform       voice1a;      //xy=75.55555555555556,112.22222222222221
AudioSynthNoiseWhite     noise3;         //xy=77.77777481079102,424.4444332122803
AudioSynthWaveform       voice3b;      //xy=80,393.3333333333333
AudioSynthWaveform       voice3a;      //xy=82.22220611572266,352.2222213745117
//AudioSynthWaveformSine   lfo;          //xy=201.11112594604492,665.5555906295776
AudioSynthWaveformDc     lfo;
AudioEffectEnvelope      envNoise2;     //xy=214.44442749023438,315.5555257797241
AudioEffectEnvelope      envNoise1;      //xy=225.55553817749023,186.66665077209473
AudioEffectEnvelope      envNoise3;     //xy=230,420
AudioEffectEnvelope      envNoise4;     //xy=232.2222137451172,529.9999904632568
AudioMixer4              mixVoice1;         //xy=372.2222328186035,148.88887882232666
AudioMixer4              mixVoice2;         //xy=375.5555610656738,252.2222204208374
AudioMixer4              mixVoice3;         //xy=380.0000228881836,363.3332853317261
AudioMixer4              mixVoice4;         //xy=384.44445991516113,482.2222909927368
AudioSynthWaveformDc     dc1;            //xy=402.22222900390625,665.555516242981
AudioEffectMultiply      multVoice2;      //xy=542.222235361735,266.6666650772095
AudioEffectMultiply      multVoice1;      //xy=548.8889020284016,146.66666507720947
AudioEffectEnvelope      envFiltVoice1;      //xy=557.7777976989746,207.77777004241943
AudioEffectEnvelope      envFiltVoice2;      //xy=563.3333464728462,323.33333174387616
AudioEffectMultiply      multVoice3;      //xy=564.4444236755371,390.0000009536743
AudioEffectEnvelope      envFiltVoice3;      //xy=571.1111242506239,448.8888872994317
AudioEffectEnvelope      envFiltVoice4;      //xy=576.6667366027832,574.4444570541382
AudioEffectMultiply      multVoice4;      //xy=577.7777881622314,514.4444265365601
AudioFilterStateVariable filter1;        //xy=746.666576385498,144.44445705413818
AudioFilterStateVariable filter4;        //xy=754.4444961547852,502.22223567962646
AudioFilterStateVariable filter2;        //xy=755.5555839538574,256.66667556762695
AudioFilterStateVariable filter3;        //xy=758.8888778686523,382.2221841812134
AudioEffectEnvelope      envVCAVoice1;      //xy=966.6666798061794,142.22222063276502
AudioEffectEnvelope      envVCAVoice2;      //xy=974.4444160461426,251.11111354827878
AudioEffectEnvelope      envVCAVoice3;      //xy=974.4444351196289,373.33330965042114
AudioEffectEnvelope      envVCAVoice4;      //xy=978.8889020284016,497.77777618832056
AudioMixer4              mixMain;         //xy=1166.6666374206543,311.11113834381104
AudioOutputI2S           i2s1;           //xy=1252.4443702697754,709.9999618530273
AudioConnection          patchCord1(noise2, envNoise2);
AudioConnection          patchCord2(noise1, envNoise1);
AudioConnection          patchCord3(voice2a, 0, mixVoice2, 0);
AudioConnection          patchCord4(voice2b, 0, mixVoice2, 1);
AudioConnection          patchCord5(noise4, envNoise4);
AudioConnection          patchCord6(voice1b, 0, mixVoice1, 1);
AudioConnection          patchCord7(voice4a, 0, mixVoice4, 0);
AudioConnection          patchCord8(voice4b, 0, mixVoice4, 1);
AudioConnection          patchCord9(voice1a, 0, mixVoice1, 0);
AudioConnection          patchCord10(noise3, envNoise3);
AudioConnection          patchCord11(voice3b, 0, mixVoice3, 1);
AudioConnection          patchCord12(voice3a, 0, mixVoice3, 0);
AudioConnection          patchCord13(lfo, 0, multVoice4, 1);
AudioConnection          patchCord14(lfo, 0, multVoice3, 1);
AudioConnection          patchCord15(lfo, 0, multVoice2, 1);
AudioConnection          patchCord16(lfo, 0, multVoice1, 1);
AudioConnection          patchCord17(envNoise2, 0, mixVoice2, 2);
AudioConnection          patchCord18(envNoise1, 0, mixVoice1, 2);
AudioConnection          patchCord19(envNoise3, 0, mixVoice3, 2);
AudioConnection          patchCord20(envNoise4, 0, mixVoice4, 2);
AudioConnection          patchCord21(mixVoice1, 0, multVoice1, 0);
AudioConnection          patchCord22(mixVoice2, 0, multVoice2, 0);
AudioConnection          patchCord23(mixVoice3, 0, multVoice3, 0);
AudioConnection          patchCord24(mixVoice4, 0, multVoice4, 0);
AudioConnection          patchCord25(dc1, envFiltVoice4);
AudioConnection          patchCord26(dc1, envFiltVoice3);
AudioConnection          patchCord27(dc1, envFiltVoice2);
AudioConnection          patchCord28(dc1, envFiltVoice1);
AudioConnection          patchCord29(multVoice2, 0, filter2, 0);
AudioConnection          patchCord30(multVoice1, 0, filter1, 0);
AudioConnection          patchCord31(envFiltVoice1, 0, filter1, 1);
AudioConnection          patchCord32(envFiltVoice2, 0, filter2, 1);
AudioConnection          patchCord33(multVoice3, 0, filter3, 0);
AudioConnection          patchCord34(envFiltVoice3, 0, filter3, 1);
AudioConnection          patchCord35(envFiltVoice4, 0, filter4, 1);
AudioConnection          patchCord36(multVoice4, 0, filter4, 0);
AudioConnection          patchCord37(filter1, 0, envVCAVoice1, 0);
AudioConnection          patchCord38(filter4, 0, envVCAVoice4, 0);
AudioConnection          patchCord39(filter2, 0, envVCAVoice2, 0);
AudioConnection          patchCord40(filter3, 0, envVCAVoice3, 0);
AudioConnection          patchCord41(envVCAVoice1, 0, mixMain, 0);
AudioConnection          patchCord42(envVCAVoice2, 0, mixMain, 1);
AudioConnection          patchCord43(envVCAVoice3, 0, mixMain, 2);
AudioConnection          patchCord44(envVCAVoice4, 0, mixMain, 3);
AudioConnection          patchCord45(mixMain, 0, i2s1, 0);
AudioConnection          patchCord46(mixMain, 0, i2s1, 1);
AudioControlSGTL5000     audioShield;     //xy=1255.5555534362793,805.5555200576782
// GUItool: end automatically generated code

// how many voices do we have?
#define VOICES 4

// maxium EG time for any envelope phase in milliseconds
// based on my hack of effect_envelope.h in the Teensy 3 audio library
#define MAX_EG_TIME 1489

#define CHANNEL_SET_PIN 2
#define DEBOUNCE_MS 20
#define LONG_CLICK_MS 1000
#define EE_CHECKBYTE_1 1022
#define EE_CHECKBYTE_2 1023
#define EE_MIDI_CHANNEL 1
#define LED_PIN 13

// midi channel; default to 1
uint8_t myChannel = 1;
// CC info from noteOn
uint8_t ccNumber;
uint8_t ccValue;

// note struct
// contains a pitch, a velocity, and a sequence number
typedef struct
{
  uint8_t myPitch;
  uint8_t myVelocity;
  uint8_t mySequence;
}
note;

// array of notes
// four notes since we have four voices
note notes[VOICES];


// array of frearduinoquencies corresponding to MIDI notes 0 to 128
const float noteFreqs[128] = {8.176,8.662,9.177,9.723,10.301,10.913,11.562,12.25,12.978,13.75,14.568,15.434,16.352,17.324,18.354,19.445,20.602,21.827,23.125,24.5,25.957,27.5,29.135,30.868,32.703,34.648,36.708,38.891,41.203,43.654,46.249,48.999,51.913,55,58.27,61.735,65.406,69.296,73.416,77.782,82.407,87.307,92.499,97.999,103.826,110,116.541,123.471,130.813,138.591,146.832,155.563,164.814,174.614,184.997,195.998,207.652,220,233.082,246.942,261.626,277.183,293.665,311.127,329.628,349.228,369.994,391.995,415.305,440,466.164,493.883,523.251,554.365,587.33,622.254,659.255,698.456,739.989,783.991,830.609,880,932.328,987.767,1046.502,1108.731,1174.659,1244.508,1318.51,1396.913,1479.978,1567.982,1661.219,1760,1864.655,1975.533,2093.005,2217.461,2349.318,2489.016,2637.02,2793.826,2959.955,3135.963,3322.438,3520,3729.31,3951.066,4186.009,4434.922,4698.636,4978.032,5274.041,5587.652,5919.911,6271.927,6644.875,7040,7458.62,7902.133,8372.018,8869.844,9397.273,9956.063,10548.08,11175.3,11839.82,12543.85};


// synth_waveform.h definitions
// #define WAVEFORM_SINE      0
// #define WAVEFORM_SAWTOOTH  1
// #define WAVEFORM_SQUARE    2
// #define WAVEFORM_TRIANGLE  3
// #define WAVEFORM_ARBITRARY 4
// #define WAVEFORM_PULSE     5


// levels from MIDI CCs
// oscillator levels
uint8_t oscACC = 64; // default to midway
uint8_t oscBCC = 64;
uint8_t noiseCC = 0;
// oscillator detune
uint8_t oscBDetuneCC = 64; // default to no detune
// pitch bend
int pitchBendCC = 0; // default to no bend
// oscillator waveform
uint8_t oscAWFCC = 22; // sawtooth
uint8_t oscBWFCC = 22; // sawtooth
// LFO level
uint8_t lfoLevelCC = 0;
// LFO rate
uint8_t lfoRateCC = 0;
// VCA envelope
uint8_t vcaAttackCC = 0;
uint8_t vcaDecayCC = 0;
uint8_t vcaSustainCC = 127;
uint8_t vcaReleaseCC = 42; // about 500 ms
// noise envelope
uint8_t noiseAttackCC = 0;
uint8_t noiseDecayCC = 0;
uint8_t noiseSustainCC = 0;
uint8_t noiseReleaseCC = 0;
// VCF envelope
uint8_t vcfAttackCC = 0;
uint8_t vcfDecayCC = 42; // about 500 ms
uint8_t vcfSustainCC = 64;
uint8_t vcfReleaseCC = 42;
// VCF parameters
uint8_t vcfCutoffCC = 127; // default to no cutoff
uint8_t vcfDepthCC = 127; // default to max range
uint8_t vcfResonanceCC = 0; // default to minimum resonance

// actual levels
// oscillator waveform
uint8_t oscAWF = 1;
uint8_t oscBWF = 1;
// oscillator frequency
float oscAFreq;
float oscBFreq;
float oscA1Freq;
float oscA2Freq;
float oscA3Freq;
float oscA4Freq;
float oscB1Freq;
float oscB2Freq;
float oscB3Freq;
float oscB4Freq;
// oscillator levels
float oscALevel = 1.0;
float oscBLevel = 1.0;
float oscA1Level;
float oscA2Level;
float oscA3Level;
float oscA4Level;
float oscB1Level;
float oscB2Level;
float oscB3Level;
float oscB4Level;
float noiseLevel = 0;
// oscillator detune
// -1 to 1 octave
float oscBDetune = 0;
// pitch bend
// -1 to 1 octave
float pitchBend = 0;
// LFO level
float lfoLevel = 0;
// LFO rate
float lfoRate = 0;
// VCA envelope
uint16_t vcaAttack = 0;
uint16_t vcaDecay = 0;
float vcaSustain = 1.0;
uint16_t vcaRelease = 500;
// noise envelope
uint16_t noiseAttack = 0;
uint16_t noiseDecay = 0;
float noiseSustain = 0;
uint16_t noiseRelease = 0;
// VCF envelope
uint16_t vcfAttack = 0;
uint16_t vcfDecay = 500;
float vcfSustain = 0.5;
uint16_t vcfRelease = 0;
// VCF parameters
float vcfCutoff = 20; // not sure if 20 Hz is the default if not defined
float vcfDepth = 1.0; // DC input to the VCF EG
float vcfResonance = 0.1; // default to zero resonance

// button setup
Bounce channelButton = Bounce();

//---------------------------------------------------------------------------------------------//
// setup
//---------------------------------------------------------------------------------------------//
void setup()
{
  
  // set up the LED pin
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // set up the button
  pinMode(CHANNEL_SET_PIN, INPUT);
  digitalWrite(CHANNEL_SET_PIN, HIGH);
  channelButton.attach(CHANNEL_SET_PIN);
  channelButton.interval(DEBOUNCE_MS);

  // read the EEPROM checkbytes
  if ((EEPROM.read(EE_CHECKBYTE_1) == 0xBA) && (EEPROM.read(EE_CHECKBYTE_2) == 0xDA))
  {
    // read the MIDI channel from EEPROM
    myChannel = EEPROM.read(EE_MIDI_CHANNEL);
  }
  else
  {
    // set the checkbytes
    EEPROM.write(EE_CHECKBYTE_1, 0xBA);
    EEPROM.write(EE_CHECKBYTE_2, 0xDA);
    // the MIDI channel will default to 1
    EEPROM.write(EE_MIDI_CHANNEL, myChannel);
  }
  
  // set up DAC/ADC shield
  AudioMemory(32);
  audioShield.enable();
  audioShield.volume(0.6);

  // stop processing while configuring things
  AudioNoInterrupts();

  // VCA envelopes
  envVCAVoice1.attack(vcaAttack);
  envVCAVoice1.hold(0.0); // not used
  envVCAVoice1.decay(vcaDecay);
  envVCAVoice1.sustain(vcaSustain);
  envVCAVoice1.release(vcaRelease);

  envVCAVoice2.attack(vcaAttack);
  envVCAVoice2.hold(0.0); // not used
  envVCAVoice2.decay(vcaDecay);
  envVCAVoice2.sustain(vcaSustain);
  envVCAVoice2.release(vcaRelease);

  envVCAVoice3.attack(vcaAttack);
  envVCAVoice3.hold(0.0); // not used
  envVCAVoice3.decay(vcaDecay);
  envVCAVoice3.sustain(vcaSustain);
  envVCAVoice3.release(vcaRelease);

  envVCAVoice4.attack(vcaAttack);
  envVCAVoice4.hold(0.0); // not used
  envVCAVoice4.decay(vcaDecay);
  envVCAVoice4.sustain(vcaSustain);
  envVCAVoice4.release(vcaRelease);
  
  // noise envelopes
  envNoise1.attack(noiseAttack);
  envNoise1.hold(0.0); // not used
  envNoise1.decay(noiseDecay);
  envNoise1.sustain(noiseSustain);
  envNoise1.release(noiseRelease);
  
  envNoise2.attack(noiseAttack);
  envNoise2.hold(0.0); // not used
  envNoise2.decay(noiseDecay);
  envNoise2.sustain(noiseSustain);
  envNoise2.release(noiseRelease);
  
  envNoise3.attack(noiseAttack);
  envNoise3.hold(0.0); // not used
  envNoise3.decay(noiseDecay);
  envNoise3.sustain(noiseSustain);
  envNoise3.release(noiseRelease);
  
  envNoise4.attack(noiseAttack);
  envNoise4.hold(0.0); // not used
  envNoise4.decay(noiseDecay);
  envNoise4.sustain(noiseSustain);
  envNoise4.release(noiseRelease);

  // VCF envelopes
  envFiltVoice1.attack(vcfAttack);
  envFiltVoice1.hold(0.0); // not used
  envFiltVoice1.decay(vcfDecay);
  envFiltVoice1.sustain(vcfSustain);
  envFiltVoice1.release(vcfRelease);

  envFiltVoice2.attack(vcfAttack);
  envFiltVoice2.hold(0.0); // not used
  envFiltVoice2.decay(vcfDecay);
  envFiltVoice2.sustain(vcfSustain);
  envFiltVoice2.release(vcfRelease);

  envFiltVoice3.attack(vcfAttack);
  envFiltVoice3.hold(0.0); // not used
  envFiltVoice3.decay(vcfDecay);
  envFiltVoice3.sustain(vcfSustain);
  envFiltVoice3.release(vcfRelease);

  envFiltVoice4.attack(vcfAttack);
  envFiltVoice4.hold(0.0); // not used
  envFiltVoice4.decay(vcfDecay);
  envFiltVoice4.sustain(vcfSustain);
  envFiltVoice4.release(vcfRelease);
  
  // noise envelopes
  envNoise1.attack(vcfAttack);
  envNoise1.hold(0.0); // not used
  envNoise1.decay(vcfDecay);
  envNoise1.sustain(vcfSustain);
  envNoise1.release(vcfRelease);

  envNoise2.attack(vcfAttack);
  envNoise2.hold(0.0); // not used
  envNoise2.decay(vcfDecay);
  envNoise2.sustain(vcfSustain);
  envNoise2.release(vcfRelease);

  envNoise3.attack(vcfAttack);
  envNoise3.hold(0.0); // not used
  envNoise3.decay(vcfDecay);
  envNoise3.sustain(vcfSustain);
  envNoise3.release(vcfRelease);

  envNoise4.attack(vcfAttack);
  envNoise4.hold(0.0); // not used
  envNoise4.decay(vcfDecay);
  envNoise4.sustain(vcfSustain);
  envNoise4.release(vcfRelease);
  
  // VCF depth control "voltage"
  dc1.amplitude(vcfDepth);

  // VCF setup
  filter1.frequency(vcfCutoff);
  filter1.resonance(vcfResonance);
  filter1.octaveControl(7); // default to the maximum range
  filter2.frequency(vcfCutoff);
  filter2.resonance(vcfResonance);
  filter2.octaveControl(7);
  filter3.frequency(vcfCutoff);
  filter3.resonance(vcfResonance);
  filter3.octaveControl(7);
  filter4.frequency(vcfCutoff);
  filter4.resonance(vcfResonance);
  filter4.octaveControl(7);

  // initialize the notes struct
  // NOTE: MIDI pitch 0 signifies no note is playing
  // despite that being a valid note.
  for (int j = 0; j < VOICES; j++)
  {
    notes[j].myPitch = 0;
    notes[j].myVelocity = 0;
    notes[j].mySequence = 0;
  }

  // resume processing
  AudioInterrupts();


  // MIDI setup
  MIDI.begin(myChannel);  
  MIDI.setHandleNoteOn(doNoteOn); 
  MIDI.setHandleControlChange(doCC); 
  MIDI.setHandleNoteOff(doNoteOff); 
  MIDI.setHandlePitchBend(doBend);
  
  // temporarily set the lfo to be a DC 'voltage' of 1.0
  // otherwise we won't hear anything
  lfo.amplitude(1.0);
}


//---------------------------------------------------------------------------------------------//
// main loop
//---------------------------------------------------------------------------------------------//
void loop()
{
  // get MIDI notes if available
  MIDI.read();
  
  // set the MIDI channel if the button is pressed
  if (channelButton.update())
  {
    if (channelButton.read() == LOW)
    {
      setMIDIChannel();
    }
  }

}

//---------------------------------------------------------------------------------------------//
// function doNoteOn
//---------------------------------------------------------------------------------------------//
void doNoteOn(byte channel, byte pitch, byte velocity)
{
  // flag if a free voice was found 
  byte voicesFree = 0;
  // the voice to be used
  byte voiceUsed = 0;
  // temporary variable for finding oldest note
  uint8_t seqNo = 0;
  int i;

  digitalWrite(LED_PIN, HIGH);

  // try to find a free voice to play the note
  for (i = 0; i < VOICES; i++)
  {
    // if a free voice is found, use it
    if (notes[i].mySequence == 0)
    {
      notes[i].myPitch = pitch;
      notes[i].myVelocity = velocity;
      // store the time
      notes[i].mySequence = 1;
      // flag it
      voicesFree = 1;
      // store the voice used so the right oscillators can be turned on
      voiceUsed = i;
      
      Serial.print("Using voice ");
      Serial.println(voiceUsed);
      
      break;
    }
    // increment the sequence number if the note is being used
    else
    {
      notes[i].mySequence = notes[i].mySequence + 1;
    }
  }

  // if no free voice was found
  // find the oldest note and use that
  if (voicesFree == 0)
  {
    for (i = 0; i < VOICES; i++)
    {
      if (notes[i].mySequence > seqNo)
      {
        seqNo = notes[i].mySequence;
        voiceUsed = i;
      }
    }

    // assign seqNo to mySequence
    notes[voiceUsed].mySequence = 1;
    // assign pitch and velocity to myPitch and myVelocity
    notes[voiceUsed].myPitch = pitch;
    notes[voiceUsed].myVelocity = velocity;
        
    Serial.print("Stealing voice ");
    Serial.println(voiceUsed);
    
    // turn off the voice being stolen
    switch (voiceUsed)
    {
      case 0:
        AudioNoInterrupts();
        envVCAVoice1.noteOff();
        envFiltVoice1.noteOff();
        AudioInterrupts();
        break;
  
      case 1:
        AudioNoInterrupts();
        envVCAVoice2.noteOff();
        envFiltVoice2.noteOff();
        AudioInterrupts();
        break;
  
      case 2:
        AudioNoInterrupts();
        envVCAVoice3.noteOff();
        envFiltVoice3.noteOff();
        AudioInterrupts();
        break;
  
      case 3:
        AudioNoInterrupts();
        envVCAVoice4.noteOff();
        envFiltVoice4.noteOff();
        AudioInterrupts();
        break;
    }
    
  }

  // voiceUsed is now the voice that will play the note

  // convert MIDI note to frequency
  oscAFreq = noteFreqs[pitch];
  oscBFreq = noteFreqs[pitch];

  // detune osc b if necessary
  if (oscBDetune != 0)
  {

    // separate cases for positive and negative
    if (oscBDetune > 0)
    {
      oscBFreq = oscBFreq + (oscBFreq * oscBDetune);
    }
    else
    {
      oscBFreq = oscBFreq + ((oscBFreq / 2) * oscBDetune);
    }
  }

  // bend osc a and b if necessary 
  // oscB is bent based on the already-detuned value
  if (pitchBend != 0)
  {
    if (pitchBend > 0)
    {
      oscAFreq = oscAFreq + (oscAFreq * pitchBend);
      oscBFreq = oscBFreq + (oscBFreq * pitchBend);
    }
    else
    {
      oscAFreq = oscAFreq + ((oscAFreq / 2) * pitchBend);
      oscBFreq = oscBFreq + ((oscBFreq / 2) * pitchBend);
    }
  }


  // start the appropriate waveforms and EGs
  // TODO: adjust the wavewform level based on the VCF resonance
  // to avoid clipping
  switch (voiceUsed)
  {
    case 0:
      oscA1Freq = oscAFreq;
      oscB1Freq = oscBFreq;
      AudioNoInterrupts();
      voice1a.begin(((velocity / 127.0) * oscALevel), oscAFreq, oscAWF);
      voice1b.begin(((velocity / 127.0) * oscBLevel), oscBFreq, oscBWF);
      envVCAVoice1.noteOn();
      envFiltVoice1.noteOn();
      AudioInterrupts();
      break;

    case 1:
      oscA2Freq = oscAFreq;
      oscB2Freq = oscBFreq;
      AudioNoInterrupts();
      voice2a.begin(((velocity / 127.0) * oscALevel), oscAFreq, oscAWF);
      voice2b.begin(((velocity / 127.0) * oscBLevel), oscBFreq, oscBWF);
      envVCAVoice2.noteOn();
      envFiltVoice2.noteOn();
      AudioInterrupts();
      break;

    case 2:
      oscA3Freq = oscAFreq;
      oscB3Freq = oscBFreq;
      AudioNoInterrupts();
      voice3a.begin(((velocity / 127.0) * oscALevel), oscAFreq, oscAWF);
      voice3b.begin(((velocity / 127.0) * oscBLevel), oscBFreq, oscBWF);
      envVCAVoice3.noteOn();
      envFiltVoice3.noteOn();
      AudioInterrupts();
      break;

    case 3:
      oscA4Freq = oscAFreq;
      oscB4Freq = oscBFreq;
      AudioNoInterrupts();
      voice4a.begin(((velocity / 127.0) * oscALevel), oscAFreq, oscAWF);
      voice4b.begin(((velocity / 127.0) * oscBLevel), oscBFreq, oscBWF);
      envVCAVoice4.noteOn();
      envFiltVoice4.noteOn();
      AudioInterrupts();
      break;
  }
  
  digitalWrite(LED_PIN, LOW);
  
} // das it mane!

//---------------------------------------------------------------------------------------------//
// function doNoteOff
//---------------------------------------------------------------------------------------------//
void doNoteOff(byte channel, byte pitch, byte velocity)
{
  // holds the voice playing the pitch
  byte voiceUsed = 0;


  // find the voice which is playing the note
  for (int i = 0; i < VOICES; i++)
  {
     if (pitch == notes[i].myPitch)
     {
       voiceUsed = i;
       // reset the voice values
       notes[i].myPitch = 0;
       notes[i].myVelocity = 0;
       notes[i].mySequence = 0;
      }
  }
  
  Serial.print("Releasing voice ");
  Serial.println(voiceUsed);

  // signal the EGs to go to release mode
  switch (voiceUsed)
  {
    case 0:
      AudioNoInterrupts();
      envVCAVoice1.noteOff();
      envFiltVoice1.noteOff();
      AudioInterrupts();
      break;

    case 1:
      AudioNoInterrupts();
      envVCAVoice2.noteOff();
      envFiltVoice2.noteOff();
      AudioInterrupts();
      break;

    case 2:
      AudioNoInterrupts();
      envVCAVoice3.noteOff();
      envFiltVoice3.noteOff();
      AudioInterrupts();
      break;

    case 3:
      AudioNoInterrupts();
      envVCAVoice4.noteOff();
      envFiltVoice4.noteOff();
      AudioInterrupts();
      break;
  }
}

//---------------------------------------------------------------------------------------------//
// function doCC
//---------------------------------------------------------------------------------------------//
void doCC(byte channel, byte ccnumber, byte ccvalue)
{

  switch (ccnumber)
  {
    // MIDI CC 19 oscillator A level
    case 19:
      oscACC = ccvalue;
      // osc1
      oscALevel = oscACC / 127.0;
      break;
  
    // MIDI CC 22 oscillator B level
    case 22:
      oscBCC = ccvalue;
      // osc1
      oscBLevel = oscBCC / 127.0;
      break;
  
    // MIDI CC 24 oscillator B detune
    case 24:
      oscBDetuneCC = ccvalue;
      // calculate detune ceneterd on 64
      if (oscBDetuneCC > 63)
      {
        oscBDetune = (oscBDetuneCC - 64) / 63.0;
      }
      else
      {
        oscBDetune = (oscBDetuneCC - 64) / 64.0;
      }
  
      // fetch the frequencies based on the notes
      // yep - we have to calculate things again
      oscB1Freq = noteFreqs[notes[0].myPitch];
      oscB2Freq = noteFreqs[notes[1].myPitch];
      oscB3Freq = noteFreqs[notes[2].myPitch];
      oscB4Freq = noteFreqs[notes[3].myPitch];
  
  
      // detune osc b
      // separate cases for positive and negative
      if (oscBDetune > 0)
      {
        oscB1Freq = oscB1Freq + (oscB1Freq * oscBDetune);
        oscB2Freq = oscB2Freq + (oscB2Freq * oscBDetune);
        oscB3Freq = oscB3Freq + (oscB3Freq * oscBDetune);
        oscB4Freq = oscB4Freq + (oscB4Freq * oscBDetune);

      }
      else
      {
        oscB1Freq = oscB1Freq + ((oscB1Freq / 2) * oscBDetune);
        oscB2Freq = oscB2Freq + ((oscB2Freq / 2) * oscBDetune);
        oscB3Freq = oscB3Freq + ((oscB3Freq / 2) * oscBDetune);
        oscB4Freq = oscB4Freq + ((oscB4Freq / 2) * oscBDetune);
      }
  
      // oscB is bent based on the already-detuned value
      if (pitchBend > 0)
      {
        oscB1Freq = oscB1Freq + (oscB1Freq * pitchBend);
        oscB2Freq = oscB2Freq + (oscB2Freq * pitchBend);
        oscB3Freq = oscB3Freq + (oscB3Freq * pitchBend);
        oscB4Freq = oscB4Freq + (oscB4Freq * pitchBend);
      }
      else
      {
        oscB1Freq = oscB1Freq + ((oscB1Freq / 2) * pitchBend);
        oscB2Freq = oscB2Freq + ((oscB2Freq / 2) * pitchBend);
        oscB3Freq = oscB3Freq + ((oscB3Freq / 2) * pitchBend);
        oscB4Freq = oscB4Freq + ((oscB4Freq / 2) * pitchBend);
      }   
      
      // apply the changes
      // this will probably sound glitchy
      AudioNoInterrupts();
      voice1b.begin(((notes[0].myVelocity / 127.0) * oscBLevel), oscB1Freq, oscBWF);
      voice2b.begin(((notes[1].myVelocity / 127.0) * oscBLevel), oscB2Freq, oscBWF);
      voice3b.begin(((notes[2].myVelocity / 127.0) * oscBLevel), oscB3Freq, oscBWF);
      voice4b.begin(((notes[3].myVelocity / 127.0) * oscBLevel), oscB4Freq, oscBWF);
      AudioInterrupts();
      break;
  
    // MIDI CC 71 VCF resonance
    case 71:
      vcfResonanceCC = ccvalue;
      // resonance varies from 0 to 5
      vcfResonance = (vcfResonanceCC / 127.0) * 5.0;
      // update the filters
      filter1.resonance(vcfResonance);
      filter2.resonance(vcfResonance);
      filter3.resonance(vcfResonance);
      filter4.resonance(vcfResonance);
      break;
  
    // MIDI CC 74 VCF cutoff
    case 74:
      vcfCutoffCC = ccvalue;
      // vary cutoff from 0 to 1000 hz
      // it's going to be pretty coarse based on just MIDI CC values
      // good enough for now
      vcfCutoff = (vcfCutoffCC / 127.0) * 1000;
      // update the filters
      filter1.frequency(vcfCutoff);
      filter2.frequency(vcfCutoff);
      filter3.frequency(vcfCutoff);
      filter4.frequency(vcfCutoff);
      break;
  
    // MIDI CC 73 VCA attack
    case 73:
      vcaAttackCC = ccvalue;
      vcaAttack = (vcaAttackCC / 127.0) * MAX_EG_TIME;
      // update envelopes
      envVCAVoice1.attack(vcaAttack);
      envVCAVoice2.attack(vcaAttack);
      envVCAVoice3.attack(vcaAttack);
      envVCAVoice4.attack(vcaAttack);
      break;
  
    // MIDI CC 85 VCA decay
    case 85:
      vcaDecayCC = ccvalue;
      vcaDecay = (vcaDecayCC / 127.0) * MAX_EG_TIME;
      // update envelopes
      envVCAVoice1.decay(vcaDecay);
      envVCAVoice2.decay(vcaDecay);
      envVCAVoice3.decay(vcaDecay);
      envVCAVoice4.decay(vcaDecay);
      break;
  
    // MIDI CC 86 VCA sustain
    case 86:
      vcaSustainCC = ccvalue;
      vcaSustain = (vcaSustainCC / 127.0) * 1.0;
      // update envelopes
      envVCAVoice1.sustain(vcaSustain);
      envVCAVoice2.sustain(vcaSustain);
      envVCAVoice3.sustain(vcaSustain);
      envVCAVoice4.sustain(vcaSustain);
      break;
  
    // MIDI CC 72 VCA release
    case 72:
      vcaReleaseCC = ccvalue;
      vcaRelease = (vcaReleaseCC / 127.0) * MAX_EG_TIME;
      // update envelopes
      envVCAVoice1.release(vcaRelease);
      envVCAVoice2.release(vcaRelease);
      envVCAVoice3.release(vcaRelease);
      envVCAVoice4.release(vcaRelease);
      break;
  
    // MIDI CC 75 VCF attack
    case 75:
      vcfAttackCC = ccvalue;
      vcfAttack = (vcfAttackCC / 127.0) * MAX_EG_TIME;
      // update envelopes
      envFiltVoice1.attack(vcfAttack);
      envFiltVoice2.attack(vcfAttack);
      envFiltVoice3.attack(vcfAttack);
      envFiltVoice4.attack(vcfAttack);
      break;
  
    // MIDI CC 76 VCF decay
    case 76:
      vcfDecayCC = ccvalue;
      vcfDecay = (vcfDecayCC / 127.0) * MAX_EG_TIME;
      // update envelopes
      envFiltVoice1.decay(vcfDecay);
      envFiltVoice2.decay(vcfDecay);
      envFiltVoice3.decay(vcfDecay);
      envFiltVoice4.decay(vcfDecay);
      break;
  
   // MIDI CC 77 VCF sustain
   case 77:
     vcfSustainCC = ccvalue;
     vcfSustain = (vcfSustainCC / 127.0) * 1.0;
     // update envelopes
     envFiltVoice1.sustain(vcfSustain);
     envFiltVoice2.sustain(vcfSustain);
     envFiltVoice3.sustain(vcfSustain);
     envFiltVoice4.sustain(vcfSustain);
     break;
  
    // MIDI CC 78 VCF release
    case 78:
      vcfReleaseCC = ccvalue;
      vcfRelease = (vcfReleaseCC / 127.0) * MAX_EG_TIME;
      // update envelopes
      envFiltVoice1.release(vcfSustain);
      envFiltVoice2.release(vcfSustain);
      envFiltVoice3.release(vcfSustain);
      envFiltVoice4.release(vcfSustain);
      break;
  
    // MIDI CC 79 OSC A waveform
    case 79:
      oscAWFCC = ccvalue;
      oscAWF = rint((oscAWFCC / 127.0) * 5);
      AudioNoInterrupts();
      voice1a.begin(((notes[0].myVelocity / 127.0) * oscALevel), oscA1Freq, oscAWF);
      voice2a.begin(((notes[1].myVelocity / 127.0) * oscALevel), oscA2Freq, oscAWF);
      voice3a.begin(((notes[2].myVelocity / 127.0) * oscALevel), oscA3Freq, oscAWF);
      voice4a.begin(((notes[3].myVelocity / 127.0) * oscALevel), oscA4Freq, oscAWF);
      AudioInterrupts();
      break;
  
    // MIDI CC 80 OSC B waveform
    case 80:
      oscBWFCC = ccvalue;
      oscBWF = rint((oscBWFCC / 127.0) * 5);
      AudioNoInterrupts();
      voice1b.begin(((notes[0].myVelocity / 127.0) * oscBLevel), oscB1Freq, oscBWF);
      voice2b.begin(((notes[1].myVelocity / 127.0) * oscBLevel), oscB2Freq, oscBWF);
      voice3b.begin(((notes[2].myVelocity / 127.0) * oscBLevel), oscB3Freq, oscBWF);
      voice4b.begin(((notes[3].myVelocity / 127.0) * oscBLevel), oscB4Freq, oscBWF);
      AudioInterrupts();
      break;
  
    // default
    default:
      break;
  }
}

//---------------------------------------------------------------------------------------------//
// function doBend
// note:
// bend is currently a full octave in either direction, which sounds bad
//---------------------------------------------------------------------------------------------//
void doBend(byte channel, int bend)
{
  pitchBendCC = bend;

  // bend is apparently -8192 to 8192
  // calculate bend ratio
  pitchBend = pitchBendCC / 8192.0;


  // fetch the frequencies based on the notes
  // yep - we have to calculate things again
  oscA1Freq = oscB1Freq = noteFreqs[notes[0].myPitch];
  oscA2Freq = oscB2Freq = noteFreqs[notes[1].myPitch];
  oscA3Freq = oscB3Freq = noteFreqs[notes[2].myPitch];
  oscA4Freq = oscB4Freq = noteFreqs[notes[3].myPitch];


  // detune osc b
  // separate cases for positive and negative
  if (oscBDetune > 0)
  {
    oscB1Freq = oscB1Freq + (oscB1Freq * oscBDetune);
    oscB2Freq = oscB2Freq + (oscB2Freq * oscBDetune);
    oscB3Freq = oscB3Freq + (oscB3Freq * oscBDetune);
    oscB4Freq = oscB4Freq + (oscB4Freq * oscBDetune);
  }
  else
  {
    oscB1Freq = oscB1Freq + ((oscB1Freq / 2) * oscBDetune);
    oscB2Freq = oscB2Freq + ((oscB2Freq / 2) * oscBDetune);
    oscB3Freq = oscB3Freq + ((oscB3Freq / 2) * oscBDetune);
    oscB4Freq = oscB4Freq + ((oscB4Freq / 2) * oscBDetune);
  }

  
  // bend osc a and b
  // oscB is bent based on the already-detuned value
  if (pitchBend > 0)
  {
    oscA1Freq = oscA1Freq + (oscA1Freq * pitchBend);
    oscB1Freq = oscB1Freq + (oscB1Freq * pitchBend);
    oscA2Freq = oscA2Freq + (oscA2Freq * pitchBend);
    oscB2Freq = oscB2Freq + (oscB2Freq * pitchBend);
    oscA3Freq = oscA3Freq + (oscA3Freq * pitchBend);
    oscB3Freq = oscB3Freq + (oscB3Freq * pitchBend);
    oscA4Freq = oscA4Freq + (oscA4Freq * pitchBend);
    oscB4Freq = oscB4Freq + (oscB4Freq * pitchBend);
  }
  else
  {
    oscA1Freq = oscA1Freq + ((oscA1Freq / 2) * pitchBend);
    oscB1Freq = oscB1Freq + ((oscB1Freq / 2) * pitchBend);
    oscA2Freq = oscA2Freq + ((oscA2Freq / 2) * pitchBend);
    oscB2Freq = oscB2Freq + ((oscB2Freq / 2) * pitchBend);
    oscA3Freq = oscA3Freq + ((oscA3Freq / 2) * pitchBend);
    oscB3Freq = oscB3Freq + ((oscB3Freq / 2) * pitchBend);
    oscA4Freq = oscA4Freq + ((oscA4Freq / 2) * pitchBend);
    oscB4Freq = oscB4Freq + ((oscB4Freq / 2) * pitchBend);
  }

  // apply the changes
  // this will probably sound glitchy
  AudioNoInterrupts();
  voice1a.begin(((notes[0].myVelocity / 127.0) * oscALevel), oscA1Freq, oscAWF);
  voice1b.begin(((notes[0].myVelocity / 127.0) * oscBLevel), oscB1Freq, oscBWF);
  voice2a.begin(((notes[1].myVelocity / 127.0) * oscALevel), oscA2Freq, oscAWF);
  voice2b.begin(((notes[1].myVelocity / 127.0) * oscBLevel), oscB2Freq, oscBWF);
  voice3a.begin(((notes[2].myVelocity / 127.0) * oscALevel), oscA3Freq, oscAWF);
  voice3b.begin(((notes[2].myVelocity / 127.0) * oscBLevel), oscB3Freq, oscBWF);
  voice4a.begin(((notes[3].myVelocity / 127.0) * oscALevel), oscA4Freq, oscAWF);
  voice4b.begin(((notes[3].myVelocity / 127.0) * oscBLevel), oscB4Freq, oscBWF);
  AudioInterrupts();
}

//---------------------------------------------------------------------------------------------//
// function setMIDIChannel
//---------------------------------------------------------------------------------------------//
void setMIDIChannel()
{
  int clickCount = 0;
  unsigned long previousMillis;
    
  // light the led for 1.0 sec to indicate set mode
  digitalWrite(LED_PIN, HIGH);
  previousMillis = millis();
  while (millis() - previousMillis < 1000)
  {
    // nothing
  }
  digitalWrite(LED_PIN, LOW);
  
  
  // loop until the channel button is held down
  while (1)
  { 
    if (channelButton.update())
    {
      if (channelButton.read() == LOW)
      {
        // start timing
        previousMillis = millis();
        // while the button is down
        while (1)
        {
          if (channelButton.update())
          {
            if (channelButton.read() == HIGH)
            {
              break;
            }
          }
        }
        // check how long the button was down
        if (millis() - previousMillis < LONG_CLICK_MS)
        {
          // count a click
          clickCount++;
        }
        else
        {
          // stop counting
          break;
        }
      }
    }
  }
  
  // light the led for 1.0 sec to indicate set mode done
  digitalWrite(LED_PIN, HIGH);
  previousMillis = millis();
  while (millis() - previousMillis < 1000)
  {
    // nothing
  }
  digitalWrite(LED_PIN, LOW);
  
  // blink back the channel
  for (int r = 0; r <= clickCount; r++)
  {
    digitalWrite(LED_PIN, HIGH);
    previousMillis = millis();
    while (millis() - previousMillis < 50)
    {
      // nothing
    }
    digitalWrite(LED_PIN, LOW);
    previousMillis = millis();
    while (millis() - previousMillis < 500)
    {
      // nothing
    }
  }
 
  // store the setting to EEPROM if not zero or greater than 15
  if ((clickCount > 0) && (clickCount < 16))
  {
    EEPROM.write(EE_MIDI_CHANNEL, clickCount);
  }
 
  return;
  
}


