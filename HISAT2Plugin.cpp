#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "HISAT2Plugin.h"

void HISAT2Plugin::input(std::string file) {
   readParameterFile(file);
}

void HISAT2Plugin::run() {}

void HISAT2Plugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 //hisat2 -p 6 --dta -x /biorg/data/DB/grch38_snp_tran/genome_snp_tran -q S12_R1.fastq -S align/S12_R1.sam
 
 myCommand += "hisat2 -p 6 --dta -x "+PluginManager::addPrefix(myParameters["database"])+" -q "+PluginManager::addPrefix(myParameters["fastq"])+" -S "+file;
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<HISAT2Plugin> HISAT2PluginProxy = PluginProxy<HISAT2Plugin>("HISAT2", PluginManager::getInstance());
