#pragma once

#include "InPack.h"
#include "OutPack.h"
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "Globals.h"

void networking(InPack & inPack, OutPack & outPack, boost::asio::ip::tcp::socket &socket, SDL_Event & event);