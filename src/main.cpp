#include <iostream>

#include "config.h"

int checkHelp(int argc, char* argv[]){
	if(argc==2){
		if( argv[1] == std::string("help") || argv[1] == std::string("-h") || argv[1] == std::string("--help")){
			std::cout << "Usage: " << argv[0] << " [CONF_FILE]" << std::endl;
			return 0;
		}
	}
}

int main(int argc,char* argv[]) {
	checkHelp(argc,argv);
	std::string configFile = "default.cfg";
	if(argc==2){
			configFile = argv[1];
	}
	std::cout <<"using config file '" << configFile << "'" << std::endl;
	Config conf;
	conf.readConfig(configFile);
	return 0;
}
