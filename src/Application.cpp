#include "pch.h"
#include "TextHandler.h"

int main()
{	
	TextHandler textHandler;
	bool running = true;

	while (running) {
		running = textHandler.conversionDialog();
	}
	return 0;
}



