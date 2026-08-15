// from vitasdk examples
#include <stdint.h>
#include <math.h>
#include <cstdlib>
#include <ctime>

#include <psp2/ctrl.h>
#include <psp2/audioout.h>
#include <psp2/kernel/processmgr.h>

#include "soloud.h"
#include "soloud_wav.h"
#include "soloud_speech.h"

SoLoud::Soloud gSoloud;
SoLoud::Wav gWave;
SoLoud::Speech gSpeech;

int main(void) {
	gSoloud.init();
    srand(time(NULL));
    int randomChoice = rand() % 100;
    if (randomChoice < 99) {
	    gWave.load("app0:/patito_vita.ogg");
	    gSoloud.play(gWave);
    } else {
	    gSpeech.setText("hello everyone. it's me. patito cuac cuac, on the p s vitaaaaaaaaaaaa!!! cuac cuac cuac cuac cuac cuac");
	    gSoloud.play(gSpeech);
    }

	while (gSoloud.getActiveVoiceCount() == 0) {
        sceKernelDelayThread(100000);
	}

	while (gSoloud.getActiveVoiceCount() > 0) {
        sceKernelDelayThread(100000);
	}

    gSoloud.deinit();
	return 0;
}
