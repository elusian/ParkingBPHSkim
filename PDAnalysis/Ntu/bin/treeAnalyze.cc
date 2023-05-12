#define UTIL_USE FULL
#include "PDAnalyzer.h"
#include "NtuAnalysis/Read/interface/NtuFlexibleAnalyzer.h"
#include "NtuTool/Common/bin/treeAnalyze.cc"
static NtuFlexibleAnalyzer<PDAnalyzer> nfa( "pdAnalysis", "pdAnalyzer" );
