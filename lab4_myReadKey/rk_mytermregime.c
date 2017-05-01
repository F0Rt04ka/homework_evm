#include "myReadkey.h"

int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint)
{
	struct termios options;
	
	if (tcgetattr(STDIN_FILENO, &options) != 0) {
		return -1;
	}

	// Установка режима терминала
	if (regime == 1) {
		options.c_lflag |= ICANON;
	} else if (regime == 0) {
		options.c_lflag &= ~ICANON;
	} else {
		return -1;
	}

	// Для неканонического режима
	if (regime == 0) {
		options.c_cc[VTIME] = vtime; // Время ожидания в децисекундах
		options.c_cc[VMIN]  = vmin; // Минимальное количество символов

		// Отображать вводимые символы
		if (echo == 1) {
			options.c_lflag |= ECHO;
		} else if (echo == 0) {
			options.c_lflag &= ~ECHO;
		} else {
			return -1;
		}

		// Когда принимаются любые символы из INTR, QUIT, SUSP или DSUSP, то генерировать соответствующий сигнал
		if (sigint == 1) {
			options.c_lflag |= ISIG;
		} else if (sigint == 0) {
			options.c_lflag &= ~ISIG;
		} else {
			return -1;
		}
	}

	if (tcsetattr(STDIN_FILENO, TCSANOW, &options) != 0) {
		return -1;
	}
	
	return 0;
}