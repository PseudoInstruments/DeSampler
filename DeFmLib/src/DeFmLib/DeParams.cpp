#include "DeParams.h"


//--------------------------------------------------------------
DeParams::DeParams(float midi_note0, float midi_note1, float vol0, float vol1)
{
	this->midi_note0 = midi_note0;
	this->midi_note1 = midi_note1;
	midi_delta_ = midi_note1 - midi_note0;

	this->db0 = db0;
	this->db1 = db1;
	db_delta_ = db1 - db0;
	float amp0 = db_to_amp_raw(db0);	
	float amp1 = db_to_amp_raw(db1);
	db_k_ = 1.0/(amp1-amp0);			// mapping v in [amp0, amp1] -> k*v + a in [0,1]
	db_a_ = -db_k_ * amp0;
}

//--------------------------------------------------------------
// https://hydrogenaud.io/index.php?topic=86414.0
// db = 20*log10(amplitude)
//      6.02 * log2(Amplitude)
//amplitude = pow(2, dB/6.02), or pow(10, dB/20)

inline float DeParams::db_to_amp_raw(float db) {
	return pow(10.0f, db / 20.0f);
}

//--------------------------------------------------------------
//0..1->0..1
float DeParams::ramp_to_volume(float x)
{
	x = x * db_delta_ + db0;
	return db_k_ * db_to_amp_raw(x) + db_a_;		
}

//--------------------------------------------------------------
// https://newt.phys.unsw.edu.au/jw/notes.html
// 69 is A, 440Hz, m=0..127
// m = 12*log2(fm/440 Hz) + 69 and fm = 2^((m-69)/12) * (440 Hz).

//0..1->Hz
float DeParams::ramp_to_freq(float x)
{
	x = x * midi_delta_ + midi_note0;
	return pow(2, (x - 69.0f) / 12.0f) * 440.0f;
}

//--------------------------------------------------------------
float DeParams::volume_to_ramp(float x)
{
	de_exception("volume_to_ramp - not implemented");
	return 0;
}

//--------------------------------------------------------------
float DeParams::freq_to_ramp(float x)
{
	de_exception("freq_to_ramp - not implemented");
	return 0;
}

//--------------------------------------------------------------
float DeParams::wavetable(float phase)
{
	return 0;// waveforms_[int(shape)].value_unsafe(phase);
}

//--------------------------------------------------------------