#include <Bela.h>
#include <q/support/literals.hpp>
#include <q/fx/delay.hpp>

namespace q = cycfi::q;
using namespace q::literals;

q::delay _delay(10000);

bool setup(BelaContext* context, void* userData)
{
	return true;
}

void render(BelaContext* context, void* userData)
{
	float _feedback = 0.5;
	for (unsigned int frame = 0; frame < context->audioFrames; ++frame)
	{
		// Get the next input sample
		auto s = audioRead(context, frame, 0);

		// Mix the signal and the delayed signal
		float _y = s + _delay();

		// Feed back the result to the delay
		_delay.push(_y * _feedback);

		// Output
		audioWrite(context, frame, 0, s);
		audioWrite(context, frame, 1, _y);
	}
}

void cleanup(BelaContext* context, void* userData)
{}
