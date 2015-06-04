##---------------------------------------------------------------------------
## Author:      Sean D'Epagnier
## Copyright:   
## License:     GPLv3+
##---------------------------------------------------------------------------
 
# define minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2)

PROJECT(calculator_pi)
SET(PACKAGE_NAME calculator_pi)
SET(CPACK_PACKAGE_CONTACT "SaltyPaws ")

SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "8")

INCLUDE("cmake/PluginConfigure.cmake")

SET(SRC_CALCULATOR
	src/calculator_pi.h
	src/calculator_pi.cpp
	src/icons.h
	src/icons.cpp
	src/calculatorgui.h
	src/calculatorgui.cpp
	src/calculatorgui_impl.cpp
	src/calculatorgui_impl.h
	src/functions.h
	src/functions.cpp
	src/units_conversion.h
	src/units_conversion.cpp
	src/OpenCPN/ocpn_plugin.h
	src/VariableFactory.h
	src/VariableFactory.cpp
	)

SET(SRC_MUPARS
	src/muparser/muParserBase.cpp
	src/muparser/muParserBase.h
	src/muparser/muParserBytecode.cpp
	src/muparser/muParserBytecode.h
	src/muparser/muParserCallback.cpp
	src/muparser/muParserCallback.h
	src/muparser/muParser.cpp
	src/muparser/muParserDef.h
	src/muparser/muParserError.cpp
	src/muparser/muParserError.h
	src/muparser/muParserFixes.h
	src/muparser/muParser.h
	src/muparser/muParserStack.h
	src/muparser/muParserToken.h
	src/muparser/muParserTokenReader.cpp
	src/muparser/muParserTokenReader.h
	src/muparser/muParserTemplateMagic.h
)




ADD_LIBRARY(${PACKAGE_NAME} SHARED ${SRC_CALCULATOR} ${SRC_MUPARS})

INCLUDE("cmake/PluginInstall.cmake")
INCLUDE("cmake/PluginLocalization.cmake")
INCLUDE("cmake/PluginPackage.cmake")
