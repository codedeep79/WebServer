#include "mongoose.h"
#include<string>
#include<iostream>
using namespace std;

static struct mg_serve_http_opts http_server;

static void eventHandler(struct mg_connection *nc, int event, void *p) {
	if (event == MG_EV_HTTP_REQUEST)
	{
		mg_serve_http(nc, (struct http_message *) p, http_server);
	}
}

int initServer(int port) {
	// Event management 
	struct mg_mgr mgr;
	// Connection
	struct mg_connection *nc;
	// Convert port to char
	string portToChar = to_string(port);
	static char const *sPort = portToChar.c_str();

	mg_mgr_init(&mgr, NULL);
	cout << "Starting Web Server on Port "<< sPort << endl;

	nc = mg_bind(&mgr, sPort, eventHandler);
	if (nc == NULL)
	{
		cout << "Failed to create listener" << endl;
		return 1;
	}
	// Setting up http connection
	mg_set_protocol_http_websocket(nc);
	http_server.document_root = ".";
	http_server.enable_directory_listing = "yes";
	for (;;)
	{
		mg_mgr_poll(&mgr, 1000);
	}

	// Free up all memory allocated
	mg_mgr_free(&mgr);
	return 0;
}
int main(int argc, char *argv[])
{
	int port;
	cout << "Select a Server Port" << endl;
	cin >> port;
	if (cin.fail())
		port = 8000;
	initServer(port);

	return 0;
}