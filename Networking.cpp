#include "Networking.h"
#include <thread>
#include <fstream>

//extern bool globalRunning;

void handler(const boost::system::error_code& error, std::size_t bytes_transferred)
{

}

void networking(InPack & inPack, OutPack & outPack, boost::asio::ip::tcp::socket &socket, SDL_Event & event)
{
	boost::array<char, 128> buf;
	

	while (globalRunning)
	{
		//aici CRAPA alta data
		std::string c;
		if (outPack.wasSet()){
		
			c = outPack.accessOutPutData();
		}
		else {
			c = "N";
		}
		boost::system::error_code ignored_error;

		//WRITE            
		boost::asio::write(socket, boost::asio::buffer(c+'\0'), ignored_error);
	
		boost::system::error_code error;


		//READ        
		size_t len = socket.read_some(boost::asio::buffer(buf), error);
		std::string temp(buf.data());



		if (temp.compare("L") == 0 || temp.compare("W") == 0)
		{
			winLose = temp;
			globalRunning = false;
		}

		if (temp.length() >1 && temp[0] != 'S' && temp[1] != 'T'){

			inPack.accessSnakesData(temp);

		}
		if (error == boost::asio::error::eof)
			break; // Connection closed cleanly by peer.
		else if (error)
			throw boost::system::system_error(error); // Some other error.

	}

}
