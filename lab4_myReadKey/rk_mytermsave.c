#include "myReadkey.h"

int rk_mytermsave(void)
{
	struct termios options;
	FILE *save;
	
	if (tcgetattr(STDIN_FILENO, &options) != 0) {
		return -1;
	}

	if ((save = fopen(SAVE_TERMINAL_FILE, "wb")) == NULL) {
        return -1;
    }

	fwrite(&options, sizeof(options), 1, save);
	fclose(save);
	
	return 0;
}
