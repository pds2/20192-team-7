#include <exception>
#include <string>

#ifndef EXCEPTION_H
#define EXCEPTION_H

namespace poker {

	class PokerError : public std::exception {
		private:
		    std::string message;

		public :
		    PokerError(std::string message);
		    std::string what();
	};
}

#endif