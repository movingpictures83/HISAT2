#ifndef HISAT2PLUGIN_H
#define HISAT2PLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class HISAT2Plugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "HISAT2";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
