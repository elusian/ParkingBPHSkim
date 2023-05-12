#!/bin/sh

cd `dirname $0`/../../..
export PD_PATH=PDAnalysis/Ntu
export PD_PACK=`pwd`/pdAnalysisReduced.tgz
rm -f ${PD_PACK}
tar -czf ${PD_PACK}                     \
${PD_PATH}/bin/PDReducedNtupleData.*   \
${PD_PATH}/bin/PDReducedNtupleReader.* \
${PD_PATH}/bin/reducedAnalyze.cc        \
${PD_PATH}/bin/compileReduced.sh        \
${PD_PATH}/bin/exportReduced.sh
echo ${PD_PACK}
