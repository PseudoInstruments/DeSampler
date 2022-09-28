#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"
#include "DeEnvelopes.h"
#include "DeEditor.h"
#include "DeFmSynth.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	string title_;

	DeParams params_;			// ��������� ����������� 0..1 � ��������� � �������
	DeEnvelopes envelopes_;		// ��������� �����������
	DeEditor editor_;			// �������� ���������
	DeFmSynth synth_;			// ����������, ��� ������� ���������� ��������� � ���������

	void load_preset(int i);
	void save_preset(int i);

};
