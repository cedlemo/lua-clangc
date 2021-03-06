/*
 * lua-clangc lua bindings for the C interface of Clang
 * Copyright (C) 2015  cedlemo <cedlemo@gmx.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "lua.h"
#include "lauxlib.h"
#include "macros.h"

void init_clang_enums_to_constants(lua_State *L){
lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Available");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Deprecated");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Notavailable");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Notaccessible");
lua_setfield(L, -2,"AvailabilityKind");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "None");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Threadbackgroundpriorityforindexing");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Threadbackgroundpriorityforediting");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Threadbackgroundpriorityforall");
lua_setfield(L, -2,"GlobalOptFlags");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Ignored");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Note");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Warning");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Error");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Fatal");
lua_setfield(L, -2,"DiagnosticSeverity");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "None");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Unknown");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Cannotload");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Invalidfile");
lua_setfield(L, -2,"LoadDiag_Error");

lua_newtable(L);
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Displaysourcelocation");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Displaycolumn");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Displaysourceranges");
lua_pushinteger(L, 8);
lua_setfield(L, -2, "Displayoption");
lua_pushinteger(L, 16);
lua_setfield(L, -2, "Displaycategoryid");
lua_pushinteger(L, 32);
lua_setfield(L, -2, "Displaycategoryname");
lua_setfield(L, -2,"DiagnosticDisplayOptions");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "None");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Detailedpreprocessingrecord");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Incomplete");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Precompiledpreamble");
lua_pushinteger(L, 8);
lua_setfield(L, -2, "Cachecompletionresults");
lua_pushinteger(L, 16);
lua_setfield(L, -2, "Forserialization");
lua_pushinteger(L, 32);
lua_setfield(L, -2, "Cxxchainedpch");
lua_pushinteger(L, 64);
lua_setfield(L, -2, "Skipfunctionbodies");
lua_pushinteger(L, 128);
lua_setfield(L, -2, "Includebriefcommentsincodecompletion");
lua_setfield(L, -2,"TranslationUnit_Flags");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "None");
lua_setfield(L, -2,"SaveTranslationUnit_Flags");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "None");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Unknown");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Translationerrors");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Invalidtu");
lua_setfield(L, -2,"SaveError");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "None");
lua_setfield(L, -2,"Reparse_Flags");

lua_newtable(L);
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Ast");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Identifiers");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Selectors");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Globalcompletionresults");
lua_pushinteger(L, 5);
lua_setfield(L, -2, "Sourcemanagercontentcache");
lua_pushinteger(L, 6);
lua_setfield(L, -2, "Ast_sidetables");
lua_pushinteger(L, 7);
lua_setfield(L, -2, "Sourcemanager_membuffer_malloc");
lua_pushinteger(L, 8);
lua_setfield(L, -2, "Sourcemanager_membuffer_mmap");
lua_pushinteger(L, 9);
lua_setfield(L, -2, "Externalastsource_membuffer_malloc");
lua_pushinteger(L, 10);
lua_setfield(L, -2, "Externalastsource_membuffer_mmap");
lua_pushinteger(L, 11);
lua_setfield(L, -2, "Preprocessor");
lua_pushinteger(L, 12);
lua_setfield(L, -2, "Preprocessingrecord");
lua_pushinteger(L, 13);
lua_setfield(L, -2, "Sourcemanager_datastructures");
lua_pushinteger(L, 14);
lua_setfield(L, -2, "Preprocessor_headersearch");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Memory_in_bytes_begin");
lua_pushinteger(L, 14);
lua_setfield(L, -2, "Memory_in_bytes_end");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "First");
lua_pushinteger(L, 14);
lua_setfield(L, -2, "Last");
lua_setfield(L, -2,"TUResourceUsageKind");

lua_newtable(L);
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Unexposeddecl");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Structdecl");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Uniondecl");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Classdecl");
lua_pushinteger(L, 5);
lua_setfield(L, -2, "Enumdecl");
lua_pushinteger(L, 6);
lua_setfield(L, -2, "Fielddecl");
lua_pushinteger(L, 7);
lua_setfield(L, -2, "Enumconstantdecl");
lua_pushinteger(L, 8);
lua_setfield(L, -2, "Functiondecl");
lua_pushinteger(L, 9);
lua_setfield(L, -2, "Vardecl");
lua_pushinteger(L, 10);
lua_setfield(L, -2, "Parmdecl");
lua_pushinteger(L, 11);
lua_setfield(L, -2, "Objcinterfacedecl");
lua_pushinteger(L, 12);
lua_setfield(L, -2, "Objccategorydecl");
lua_pushinteger(L, 13);
lua_setfield(L, -2, "Objcprotocoldecl");
lua_pushinteger(L, 14);
lua_setfield(L, -2, "Objcpropertydecl");
lua_pushinteger(L, 15);
lua_setfield(L, -2, "Objcivardecl");
lua_pushinteger(L, 16);
lua_setfield(L, -2, "Objcinstancemethoddecl");
lua_pushinteger(L, 17);
lua_setfield(L, -2, "Objcclassmethoddecl");
lua_pushinteger(L, 18);
lua_setfield(L, -2, "Objcimplementationdecl");
lua_pushinteger(L, 19);
lua_setfield(L, -2, "Objccategoryimpldecl");
lua_pushinteger(L, 20);
lua_setfield(L, -2, "Typedefdecl");
lua_pushinteger(L, 21);
lua_setfield(L, -2, "Cxxmethod");
lua_pushinteger(L, 22);
lua_setfield(L, -2, "Namespace");
lua_pushinteger(L, 23);
lua_setfield(L, -2, "Linkagespec");
lua_pushinteger(L, 24);
lua_setfield(L, -2, "Constructor");
lua_pushinteger(L, 25);
lua_setfield(L, -2, "Destructor");
lua_pushinteger(L, 26);
lua_setfield(L, -2, "Conversionfunction");
lua_pushinteger(L, 27);
lua_setfield(L, -2, "Templatetypeparameter");
lua_pushinteger(L, 28);
lua_setfield(L, -2, "Nontypetemplateparameter");
lua_pushinteger(L, 29);
lua_setfield(L, -2, "Templatetemplateparameter");
lua_pushinteger(L, 30);
lua_setfield(L, -2, "Functiontemplate");
lua_pushinteger(L, 31);
lua_setfield(L, -2, "Classtemplate");
lua_pushinteger(L, 32);
lua_setfield(L, -2, "Classtemplatepartialspecialization");
lua_pushinteger(L, 33);
lua_setfield(L, -2, "Namespacealias");
lua_pushinteger(L, 34);
lua_setfield(L, -2, "Usingdirective");
lua_pushinteger(L, 35);
lua_setfield(L, -2, "Usingdeclaration");
lua_pushinteger(L, 36);
lua_setfield(L, -2, "Typealiasdecl");
lua_pushinteger(L, 37);
lua_setfield(L, -2, "Objcsynthesizedecl");
lua_pushinteger(L, 38);
lua_setfield(L, -2, "Objcdynamicdecl");
lua_pushinteger(L, 39);
lua_setfield(L, -2, "Cxxaccessspecifier");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Firstdecl");
lua_pushinteger(L, 39);
lua_setfield(L, -2, "Lastdecl");
lua_pushinteger(L, 40);
lua_setfield(L, -2, "Firstref");
lua_pushinteger(L, 40);
lua_setfield(L, -2, "Objcsuperclassref");
lua_pushinteger(L, 41);
lua_setfield(L, -2, "Objcprotocolref");
lua_pushinteger(L, 42);
lua_setfield(L, -2, "Objcclassref");
lua_pushinteger(L, 43);
lua_setfield(L, -2, "Typeref");
lua_pushinteger(L, 44);
lua_setfield(L, -2, "Cxxbasespecifier");
lua_pushinteger(L, 45);
lua_setfield(L, -2, "Templateref");
lua_pushinteger(L, 46);
lua_setfield(L, -2, "Namespaceref");
lua_pushinteger(L, 47);
lua_setfield(L, -2, "Memberref");
lua_pushinteger(L, 48);
lua_setfield(L, -2, "Labelref");
lua_pushinteger(L, 49);
lua_setfield(L, -2, "Overloadeddeclref");
lua_pushinteger(L, 50);
lua_setfield(L, -2, "Variableref");
lua_pushinteger(L, 50);
lua_setfield(L, -2, "Lastref");
lua_pushinteger(L, 70);
lua_setfield(L, -2, "Firstinvalid");
lua_pushinteger(L, 70);
lua_setfield(L, -2, "Invalidfile");
lua_pushinteger(L, 71);
lua_setfield(L, -2, "Nodeclfound");
lua_pushinteger(L, 72);
lua_setfield(L, -2, "Notimplemented");
lua_pushinteger(L, 73);
lua_setfield(L, -2, "Invalidcode");
lua_pushinteger(L, 73);
lua_setfield(L, -2, "Lastinvalid");
lua_pushinteger(L, 100);
lua_setfield(L, -2, "Firstexpr");
lua_pushinteger(L, 100);
lua_setfield(L, -2, "Unexposedexpr");
lua_pushinteger(L, 101);
lua_setfield(L, -2, "Declrefexpr");
lua_pushinteger(L, 102);
lua_setfield(L, -2, "Memberrefexpr");
lua_pushinteger(L, 103);
lua_setfield(L, -2, "Callexpr");
lua_pushinteger(L, 104);
lua_setfield(L, -2, "Objcmessageexpr");
lua_pushinteger(L, 105);
lua_setfield(L, -2, "Blockexpr");
lua_pushinteger(L, 106);
lua_setfield(L, -2, "Integerliteral");
lua_pushinteger(L, 107);
lua_setfield(L, -2, "Floatingliteral");
lua_pushinteger(L, 108);
lua_setfield(L, -2, "Imaginaryliteral");
lua_pushinteger(L, 109);
lua_setfield(L, -2, "Stringliteral");
lua_pushinteger(L, 110);
lua_setfield(L, -2, "Characterliteral");
lua_pushinteger(L, 111);
lua_setfield(L, -2, "Parenexpr");
lua_pushinteger(L, 112);
lua_setfield(L, -2, "Unaryoperator");
lua_pushinteger(L, 113);
lua_setfield(L, -2, "Arraysubscriptexpr");
lua_pushinteger(L, 114);
lua_setfield(L, -2, "Binaryoperator");
lua_pushinteger(L, 115);
lua_setfield(L, -2, "Compoundassignoperator");
lua_pushinteger(L, 116);
lua_setfield(L, -2, "Conditionaloperator");
lua_pushinteger(L, 117);
lua_setfield(L, -2, "Cstylecastexpr");
lua_pushinteger(L, 118);
lua_setfield(L, -2, "Compoundliteralexpr");
lua_pushinteger(L, 119);
lua_setfield(L, -2, "Initlistexpr");
lua_pushinteger(L, 120);
lua_setfield(L, -2, "Addrlabelexpr");
lua_pushinteger(L, 121);
lua_setfield(L, -2, "Stmtexpr");
lua_pushinteger(L, 122);
lua_setfield(L, -2, "Genericselectionexpr");
lua_pushinteger(L, 123);
lua_setfield(L, -2, "Gnunullexpr");
lua_pushinteger(L, 124);
lua_setfield(L, -2, "Cxxstaticcastexpr");
lua_pushinteger(L, 125);
lua_setfield(L, -2, "Cxxdynamiccastexpr");
lua_pushinteger(L, 126);
lua_setfield(L, -2, "Cxxreinterpretcastexpr");
lua_pushinteger(L, 127);
lua_setfield(L, -2, "Cxxconstcastexpr");
lua_pushinteger(L, 128);
lua_setfield(L, -2, "Cxxfunctionalcastexpr");
lua_pushinteger(L, 129);
lua_setfield(L, -2, "Cxxtypeidexpr");
lua_pushinteger(L, 130);
lua_setfield(L, -2, "Cxxboolliteralexpr");
lua_pushinteger(L, 131);
lua_setfield(L, -2, "Cxxnullptrliteralexpr");
lua_pushinteger(L, 132);
lua_setfield(L, -2, "Cxxthisexpr");
lua_pushinteger(L, 133);
lua_setfield(L, -2, "Cxxthrowexpr");
lua_pushinteger(L, 134);
lua_setfield(L, -2, "Cxxnewexpr");
lua_pushinteger(L, 135);
lua_setfield(L, -2, "Cxxdeleteexpr");
lua_pushinteger(L, 136);
lua_setfield(L, -2, "Unaryexpr");
lua_pushinteger(L, 137);
lua_setfield(L, -2, "Objcstringliteral");
lua_pushinteger(L, 138);
lua_setfield(L, -2, "Objcencodeexpr");
lua_pushinteger(L, 139);
lua_setfield(L, -2, "Objcselectorexpr");
lua_pushinteger(L, 140);
lua_setfield(L, -2, "Objcprotocolexpr");
lua_pushinteger(L, 141);
lua_setfield(L, -2, "Objcbridgedcastexpr");
lua_pushinteger(L, 142);
lua_setfield(L, -2, "Packexpansionexpr");
lua_pushinteger(L, 143);
lua_setfield(L, -2, "Sizeofpackexpr");
lua_pushinteger(L, 144);
lua_setfield(L, -2, "Lambdaexpr");
lua_pushinteger(L, 145);
lua_setfield(L, -2, "Objcboolliteralexpr");
lua_pushinteger(L, 146);
lua_setfield(L, -2, "Objcselfexpr");
lua_pushinteger(L, 146);
lua_setfield(L, -2, "Lastexpr");
lua_pushinteger(L, 200);
lua_setfield(L, -2, "Firststmt");
lua_pushinteger(L, 200);
lua_setfield(L, -2, "Unexposedstmt");
lua_pushinteger(L, 201);
lua_setfield(L, -2, "Labelstmt");
lua_pushinteger(L, 202);
lua_setfield(L, -2, "Compoundstmt");
lua_pushinteger(L, 203);
lua_setfield(L, -2, "Casestmt");
lua_pushinteger(L, 204);
lua_setfield(L, -2, "Defaultstmt");
lua_pushinteger(L, 205);
lua_setfield(L, -2, "Ifstmt");
lua_pushinteger(L, 206);
lua_setfield(L, -2, "Switchstmt");
lua_pushinteger(L, 207);
lua_setfield(L, -2, "Whilestmt");
lua_pushinteger(L, 208);
lua_setfield(L, -2, "Dostmt");
lua_pushinteger(L, 209);
lua_setfield(L, -2, "Forstmt");
lua_pushinteger(L, 210);
lua_setfield(L, -2, "Gotostmt");
lua_pushinteger(L, 211);
lua_setfield(L, -2, "Indirectgotostmt");
lua_pushinteger(L, 212);
lua_setfield(L, -2, "Continuestmt");
lua_pushinteger(L, 213);
lua_setfield(L, -2, "Breakstmt");
lua_pushinteger(L, 214);
lua_setfield(L, -2, "Returnstmt");
lua_pushinteger(L, 215);
lua_setfield(L, -2, "Gccasmstmt");
lua_pushinteger(L, 215);
lua_setfield(L, -2, "Asmstmt");
lua_pushinteger(L, 216);
lua_setfield(L, -2, "Objcattrystmt");
lua_pushinteger(L, 217);
lua_setfield(L, -2, "Objcatcatchstmt");
lua_pushinteger(L, 218);
lua_setfield(L, -2, "Objcatfinallystmt");
lua_pushinteger(L, 219);
lua_setfield(L, -2, "Objcatthrowstmt");
lua_pushinteger(L, 220);
lua_setfield(L, -2, "Objcatsynchronizedstmt");
lua_pushinteger(L, 221);
lua_setfield(L, -2, "Objcautoreleasepoolstmt");
lua_pushinteger(L, 222);
lua_setfield(L, -2, "Objcforcollectionstmt");
lua_pushinteger(L, 223);
lua_setfield(L, -2, "Cxxcatchstmt");
lua_pushinteger(L, 224);
lua_setfield(L, -2, "Cxxtrystmt");
lua_pushinteger(L, 225);
lua_setfield(L, -2, "Cxxforrangestmt");
lua_pushinteger(L, 226);
lua_setfield(L, -2, "Sehtrystmt");
lua_pushinteger(L, 227);
lua_setfield(L, -2, "Sehexceptstmt");
lua_pushinteger(L, 228);
lua_setfield(L, -2, "Sehfinallystmt");
lua_pushinteger(L, 229);
lua_setfield(L, -2, "Msasmstmt");
lua_pushinteger(L, 230);
lua_setfield(L, -2, "Nullstmt");
lua_pushinteger(L, 231);
lua_setfield(L, -2, "Declstmt");
lua_pushinteger(L, 232);
lua_setfield(L, -2, "Ompparalleldirective");
lua_pushinteger(L, 233);
lua_setfield(L, -2, "Ompsimddirective");
lua_pushinteger(L, 234);
lua_setfield(L, -2, "Ompfordirective");
lua_pushinteger(L, 235);
lua_setfield(L, -2, "Ompsectionsdirective");
lua_pushinteger(L, 236);
lua_setfield(L, -2, "Ompsectiondirective");
lua_pushinteger(L, 237);
lua_setfield(L, -2, "Ompsingledirective");
lua_pushinteger(L, 238);
lua_setfield(L, -2, "Ompparallelfordirective");
lua_pushinteger(L, 239);
lua_setfield(L, -2, "Ompparallelsectionsdirective");
lua_pushinteger(L, 240);
lua_setfield(L, -2, "Omptaskdirective");
lua_pushinteger(L, 241);
lua_setfield(L, -2, "Ompmasterdirective");
lua_pushinteger(L, 242);
lua_setfield(L, -2, "Ompcriticaldirective");
lua_pushinteger(L, 243);
lua_setfield(L, -2, "Omptaskyielddirective");
lua_pushinteger(L, 244);
lua_setfield(L, -2, "Ompbarrierdirective");
lua_pushinteger(L, 245);
lua_setfield(L, -2, "Omptaskwaitdirective");
lua_pushinteger(L, 246);
lua_setfield(L, -2, "Ompflushdirective");
lua_pushinteger(L, 247);
lua_setfield(L, -2, "Sehleavestmt");
lua_pushinteger(L, 248);
lua_setfield(L, -2, "Ompordereddirective");
lua_pushinteger(L, 249);
lua_setfield(L, -2, "Ompatomicdirective");
lua_pushinteger(L, 250);
lua_setfield(L, -2, "Ompforsimddirective");
lua_pushinteger(L, 251);
lua_setfield(L, -2, "Ompparallelforsimddirective");
lua_pushinteger(L, 252);
lua_setfield(L, -2, "Omptargetdirective");
lua_pushinteger(L, 253);
lua_setfield(L, -2, "Ompteamsdirective");
lua_pushinteger(L, 253);
lua_setfield(L, -2, "Laststmt");
lua_pushinteger(L, 300);
lua_setfield(L, -2, "Translationunit");
lua_pushinteger(L, 400);
lua_setfield(L, -2, "Firstattr");
lua_pushinteger(L, 400);
lua_setfield(L, -2, "Unexposedattr");
lua_pushinteger(L, 401);
lua_setfield(L, -2, "Ibactionattr");
lua_pushinteger(L, 402);
lua_setfield(L, -2, "Iboutletattr");
lua_pushinteger(L, 403);
lua_setfield(L, -2, "Iboutletcollectionattr");
lua_pushinteger(L, 404);
lua_setfield(L, -2, "Cxxfinalattr");
lua_pushinteger(L, 405);
lua_setfield(L, -2, "Cxxoverrideattr");
lua_pushinteger(L, 406);
lua_setfield(L, -2, "Annotateattr");
lua_pushinteger(L, 407);
lua_setfield(L, -2, "Asmlabelattr");
lua_pushinteger(L, 408);
lua_setfield(L, -2, "Packedattr");
lua_pushinteger(L, 409);
lua_setfield(L, -2, "Pureattr");
lua_pushinteger(L, 410);
lua_setfield(L, -2, "Constattr");
lua_pushinteger(L, 411);
lua_setfield(L, -2, "Noduplicateattr");
lua_pushinteger(L, 412);
lua_setfield(L, -2, "Cudaconstantattr");
lua_pushinteger(L, 413);
lua_setfield(L, -2, "Cudadeviceattr");
lua_pushinteger(L, 414);
lua_setfield(L, -2, "Cudaglobalattr");
lua_pushinteger(L, 415);
lua_setfield(L, -2, "Cudahostattr");
lua_pushinteger(L, 416);
lua_setfield(L, -2, "Cudasharedattr");
lua_pushinteger(L, 416);
lua_setfield(L, -2, "Lastattr");
lua_pushinteger(L, 500);
lua_setfield(L, -2, "Preprocessingdirective");
lua_pushinteger(L, 501);
lua_setfield(L, -2, "Macrodefinition");
lua_pushinteger(L, 502);
lua_setfield(L, -2, "Macroexpansion");
lua_pushinteger(L, 502);
lua_setfield(L, -2, "Macroinstantiation");
lua_pushinteger(L, 503);
lua_setfield(L, -2, "Inclusiondirective");
lua_pushinteger(L, 500);
lua_setfield(L, -2, "Firstpreprocessing");
lua_pushinteger(L, 503);
lua_setfield(L, -2, "Lastpreprocessing");
lua_pushinteger(L, 600);
lua_setfield(L, -2, "Moduleimportdecl");
lua_pushinteger(L, 600);
lua_setfield(L, -2, "Firstextradecl");
lua_pushinteger(L, 600);
lua_setfield(L, -2, "Lastextradecl");
lua_setfield(L, -2,"CursorKind");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Invalid");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Nolinkage");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Internal");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Uniqueexternal");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "External");
lua_setfield(L, -2,"LinkageKind");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Invalid");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "C");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Objc");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Cplusplus");
lua_setfield(L, -2,"LanguageKind");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Invalid");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Unexposed");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Void");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Bool");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Char_u");
lua_pushinteger(L, 5);
lua_setfield(L, -2, "Uchar");
lua_pushinteger(L, 6);
lua_setfield(L, -2, "Char16");
lua_pushinteger(L, 7);
lua_setfield(L, -2, "Char32");
lua_pushinteger(L, 8);
lua_setfield(L, -2, "Ushort");
lua_pushinteger(L, 9);
lua_setfield(L, -2, "Uint");
lua_pushinteger(L, 10);
lua_setfield(L, -2, "Ulong");
lua_pushinteger(L, 11);
lua_setfield(L, -2, "Ulonglong");
lua_pushinteger(L, 12);
lua_setfield(L, -2, "Uint128");
lua_pushinteger(L, 13);
lua_setfield(L, -2, "Char_s");
lua_pushinteger(L, 14);
lua_setfield(L, -2, "Schar");
lua_pushinteger(L, 15);
lua_setfield(L, -2, "Wchar");
lua_pushinteger(L, 16);
lua_setfield(L, -2, "Short");
lua_pushinteger(L, 17);
lua_setfield(L, -2, "Int");
lua_pushinteger(L, 18);
lua_setfield(L, -2, "Long");
lua_pushinteger(L, 19);
lua_setfield(L, -2, "Longlong");
lua_pushinteger(L, 20);
lua_setfield(L, -2, "Int128");
lua_pushinteger(L, 21);
lua_setfield(L, -2, "Float");
lua_pushinteger(L, 22);
lua_setfield(L, -2, "Double");
lua_pushinteger(L, 23);
lua_setfield(L, -2, "Longdouble");
lua_pushinteger(L, 24);
lua_setfield(L, -2, "Nullptr");
lua_pushinteger(L, 25);
lua_setfield(L, -2, "Overload");
lua_pushinteger(L, 26);
lua_setfield(L, -2, "Dependent");
lua_pushinteger(L, 27);
lua_setfield(L, -2, "Objcid");
lua_pushinteger(L, 28);
lua_setfield(L, -2, "Objcclass");
lua_pushinteger(L, 29);
lua_setfield(L, -2, "Objcsel");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Firstbuiltin");
lua_pushinteger(L, 29);
lua_setfield(L, -2, "Lastbuiltin");
lua_pushinteger(L, 100);
lua_setfield(L, -2, "Complex");
lua_pushinteger(L, 101);
lua_setfield(L, -2, "Pointer");
lua_pushinteger(L, 102);
lua_setfield(L, -2, "Blockpointer");
lua_pushinteger(L, 103);
lua_setfield(L, -2, "Lvaluereference");
lua_pushinteger(L, 104);
lua_setfield(L, -2, "Rvaluereference");
lua_pushinteger(L, 105);
lua_setfield(L, -2, "Record");
lua_pushinteger(L, 106);
lua_setfield(L, -2, "Enum");
lua_pushinteger(L, 107);
lua_setfield(L, -2, "Typedef");
lua_pushinteger(L, 108);
lua_setfield(L, -2, "Objcinterface");
lua_pushinteger(L, 109);
lua_setfield(L, -2, "Objcobjectpointer");
lua_pushinteger(L, 110);
lua_setfield(L, -2, "Functionnoproto");
lua_pushinteger(L, 111);
lua_setfield(L, -2, "Functionproto");
lua_pushinteger(L, 112);
lua_setfield(L, -2, "Constantarray");
lua_pushinteger(L, 113);
lua_setfield(L, -2, "Vector");
lua_pushinteger(L, 114);
lua_setfield(L, -2, "Incompletearray");
lua_pushinteger(L, 115);
lua_setfield(L, -2, "Variablearray");
lua_pushinteger(L, 116);
lua_setfield(L, -2, "Dependentsizedarray");
lua_pushinteger(L, 117);
lua_setfield(L, -2, "Memberpointer");
lua_setfield(L, -2,"TypeKind");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Default");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "C");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "X86stdcall");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "X86fastcall");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "X86thiscall");
lua_pushinteger(L, 5);
lua_setfield(L, -2, "X86pascal");
lua_pushinteger(L, 6);
lua_setfield(L, -2, "Aapcs");
lua_pushinteger(L, 7);
lua_setfield(L, -2, "Aapcs_vfp");
lua_pushinteger(L, 8);
lua_setfield(L, -2, "Pnaclcall");
lua_pushinteger(L, 9);
lua_setfield(L, -2, "Inteloclbicc");
lua_pushinteger(L, 10);
lua_setfield(L, -2, "X86_64win64");
lua_pushinteger(L, 11);
lua_setfield(L, -2, "X86_64sysv");
lua_pushinteger(L, 12);
lua_setfield(L, -2, "X86vectorcall");
lua_pushinteger(L, 100);
lua_setfield(L, -2, "Invalid");
lua_pushinteger(L, 200);
lua_setfield(L, -2, "Unexposed");
lua_setfield(L, -2,"CallingConv");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Null");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Type");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Declaration");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Nullptr");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Integral");
lua_pushinteger(L, 5);
lua_setfield(L, -2, "Template");
lua_pushinteger(L, 6);
lua_setfield(L, -2, "Templateexpansion");
lua_pushinteger(L, 7);
lua_setfield(L, -2, "Expression");
lua_pushinteger(L, 8);
lua_setfield(L, -2, "Pack");
lua_pushinteger(L, 9);
lua_setfield(L, -2, "Invalid");
lua_setfield(L, -2,"TemplateArgumentKind");

lua_newtable(L);
lua_pushinteger(L, -1);
lua_setfield(L, -2, "Invalid");
lua_pushinteger(L, -2);
lua_setfield(L, -2, "Incomplete");
lua_pushinteger(L, -3);
lua_setfield(L, -2, "Dependent");
lua_pushinteger(L, -4);
lua_setfield(L, -2, "Notconstantsize");
lua_pushinteger(L, -5);
lua_setfield(L, -2, "Invalidfieldname");
lua_setfield(L, -2,"TypeLayoutError");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "None");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Lvalue");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Rvalue");
lua_setfield(L, -2,"RefQualifierKind");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Cxxinvalidaccessspecifier");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Cxxpublic");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Cxxprotected");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Cxxprivate");
lua_setfield(L, -2,"_XAccessSpecifier");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Sc_invalid");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Sc_none");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Sc_extern");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Sc_static");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Sc_privateextern");
lua_pushinteger(L, 5);
lua_setfield(L, -2, "Sc_openclworkgrouplocal");
lua_pushinteger(L, 6);
lua_setfield(L, -2, "Sc_auto");
lua_pushinteger(L, 7);
lua_setfield(L, -2, "Sc_register");
lua_setfield(L, -2,"_StorageClass");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Break");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Continue");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Recurse");
lua_setfield(L, -2,"ChildVisitResult");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Noattr");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Readonly");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Getter");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Assign");
lua_pushinteger(L, 8);
lua_setfield(L, -2, "Readwrite");
lua_pushinteger(L, 16);
lua_setfield(L, -2, "Retain");
lua_pushinteger(L, 32);
lua_setfield(L, -2, "Copy");
lua_pushinteger(L, 64);
lua_setfield(L, -2, "Nonatomic");
lua_pushinteger(L, 128);
lua_setfield(L, -2, "Setter");
lua_pushinteger(L, 256);
lua_setfield(L, -2, "Atomic");
lua_pushinteger(L, 512);
lua_setfield(L, -2, "Weak");
lua_pushinteger(L, 1024);
lua_setfield(L, -2, "Strong");
lua_pushinteger(L, 2048);
lua_setfield(L, -2, "Unsafe_unretained");
lua_setfield(L, -2,"ObjCPropertyAttrKind");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "None");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "In");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Inout");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Out");
lua_pushinteger(L, 8);
lua_setfield(L, -2, "Bycopy");
lua_pushinteger(L, 16);
lua_setfield(L, -2, "Byref");
lua_pushinteger(L, 32);
lua_setfield(L, -2, "Oneway");
lua_setfield(L, -2,"ObjCDeclQualifierKind");

lua_newtable(L);
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Wantqualifier");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Wanttemplateargs");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Wantsinglepiece");
lua_setfield(L, -2,"NameRefFlags");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Punctuation");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Keyword");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Identifier");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Literal");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Comment");
lua_setfield(L, -2,"TokenKind");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Optional");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Typedtext");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Text");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Placeholder");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Informative");
lua_pushinteger(L, 5);
lua_setfield(L, -2, "Currentparameter");
lua_pushinteger(L, 6);
lua_setfield(L, -2, "Leftparen");
lua_pushinteger(L, 7);
lua_setfield(L, -2, "Rightparen");
lua_pushinteger(L, 8);
lua_setfield(L, -2, "Leftbracket");
lua_pushinteger(L, 9);
lua_setfield(L, -2, "Rightbracket");
lua_pushinteger(L, 10);
lua_setfield(L, -2, "Leftbrace");
lua_pushinteger(L, 11);
lua_setfield(L, -2, "Rightbrace");
lua_pushinteger(L, 12);
lua_setfield(L, -2, "Leftangle");
lua_pushinteger(L, 13);
lua_setfield(L, -2, "Rightangle");
lua_pushinteger(L, 14);
lua_setfield(L, -2, "Comma");
lua_pushinteger(L, 15);
lua_setfield(L, -2, "Resulttype");
lua_pushinteger(L, 16);
lua_setfield(L, -2, "Colon");
lua_pushinteger(L, 17);
lua_setfield(L, -2, "Semicolon");
lua_pushinteger(L, 18);
lua_setfield(L, -2, "Equal");
lua_pushinteger(L, 19);
lua_setfield(L, -2, "Horizontalspace");
lua_pushinteger(L, 20);
lua_setfield(L, -2, "Verticalspace");
lua_setfield(L, -2,"CompletionChunkKind");

lua_newtable(L);
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Includemacros");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Includecodepatterns");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Includebriefcomments");
lua_setfield(L, -2,"CodeComplete_Flags");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Unexposed");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Anytype");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Anyvalue");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Objcobjectvalue");
lua_pushinteger(L, 8);
lua_setfield(L, -2, "Objcselectorvalue");
lua_pushinteger(L, 16);
lua_setfield(L, -2, "Cxxclasstypevalue");
lua_pushinteger(L, 32);
lua_setfield(L, -2, "Dotmemberaccess");
lua_pushinteger(L, 64);
lua_setfield(L, -2, "Arrowmemberaccess");
lua_pushinteger(L, 128);
lua_setfield(L, -2, "Objcpropertyaccess");
lua_pushinteger(L, 256);
lua_setfield(L, -2, "Enumtag");
lua_pushinteger(L, 512);
lua_setfield(L, -2, "Uniontag");
lua_pushinteger(L, 1024);
lua_setfield(L, -2, "Structtag");
lua_pushinteger(L, 2048);
lua_setfield(L, -2, "Classtag");
lua_pushinteger(L, 4096);
lua_setfield(L, -2, "Namespace");
lua_pushinteger(L, 8192);
lua_setfield(L, -2, "Nestednamespecifier");
lua_pushinteger(L, 16384);
lua_setfield(L, -2, "Objcinterface");
lua_pushinteger(L, 32768);
lua_setfield(L, -2, "Objcprotocol");
lua_pushinteger(L, 65536);
lua_setfield(L, -2, "Objccategory");
lua_pushinteger(L, 131072);
lua_setfield(L, -2, "Objcinstancemessage");
lua_pushinteger(L, 262144);
lua_setfield(L, -2, "Objcclassmessage");
lua_pushinteger(L, 524288);
lua_setfield(L, -2, "Objcselectorname");
lua_pushinteger(L, 1048576);
lua_setfield(L, -2, "Macroname");
lua_pushinteger(L, 2097152);
lua_setfield(L, -2, "Naturallanguage");
lua_pushinteger(L, 4194303);
lua_setfield(L, -2, "Unknown");
lua_setfield(L, -2,"CompletionContext");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Break");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Continue");
lua_setfield(L, -2,"VisitorResult");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Success");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Invalid");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Visitbreak");
lua_setfield(L, -2,"Result");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Unexposed");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Typedef");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Function");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Variable");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Field");
lua_pushinteger(L, 5);
lua_setfield(L, -2, "Enumconstant");
lua_pushinteger(L, 6);
lua_setfield(L, -2, "Objcclass");
lua_pushinteger(L, 7);
lua_setfield(L, -2, "Objcprotocol");
lua_pushinteger(L, 8);
lua_setfield(L, -2, "Objccategory");
lua_pushinteger(L, 9);
lua_setfield(L, -2, "Objcinstancemethod");
lua_pushinteger(L, 10);
lua_setfield(L, -2, "Objcclassmethod");
lua_pushinteger(L, 11);
lua_setfield(L, -2, "Objcproperty");
lua_pushinteger(L, 12);
lua_setfield(L, -2, "Objcivar");
lua_pushinteger(L, 13);
lua_setfield(L, -2, "Enum");
lua_pushinteger(L, 14);
lua_setfield(L, -2, "Struct");
lua_pushinteger(L, 15);
lua_setfield(L, -2, "Union");
lua_pushinteger(L, 16);
lua_setfield(L, -2, "Cxxclass");
lua_pushinteger(L, 17);
lua_setfield(L, -2, "Cxxnamespace");
lua_pushinteger(L, 18);
lua_setfield(L, -2, "Cxxnamespacealias");
lua_pushinteger(L, 19);
lua_setfield(L, -2, "Cxxstaticvariable");
lua_pushinteger(L, 20);
lua_setfield(L, -2, "Cxxstaticmethod");
lua_pushinteger(L, 21);
lua_setfield(L, -2, "Cxxinstancemethod");
lua_pushinteger(L, 22);
lua_setfield(L, -2, "Cxxconstructor");
lua_pushinteger(L, 23);
lua_setfield(L, -2, "Cxxdestructor");
lua_pushinteger(L, 24);
lua_setfield(L, -2, "Cxxconversionfunction");
lua_pushinteger(L, 25);
lua_setfield(L, -2, "Cxxtypealias");
lua_pushinteger(L, 26);
lua_setfield(L, -2, "Cxxinterface");
lua_setfield(L, -2,"IdxEntityKind");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "None");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "C");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Objc");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Cxx");
lua_setfield(L, -2,"IdxEntityLanguage");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Nontemplate");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Template");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Templatepartialspecialization");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Templatespecialization");
lua_setfield(L, -2,"IdxEntityXTemplateKind");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Unexposed");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Ibaction");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Iboutlet");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Iboutletcollection");
lua_setfield(L, -2,"IdxAttrKind");

lua_newtable(L);
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Skipped");
lua_setfield(L, -2,"IdxDeclInfoFlags");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Forwardref");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Interface");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Implementation");
lua_setfield(L, -2,"IdxObjCContainerKind");

lua_newtable(L);
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Direct");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Implicit");
lua_setfield(L, -2,"IdxEntityRefKind");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "None");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Suppressredundantrefs");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Indexfunctionlocalsymbols");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Indeximplicittemplateinstantiations");
lua_pushinteger(L, 8);
lua_setfield(L, -2, "Suppresswarnings");
lua_pushinteger(L, 16);
lua_setfield(L, -2, "Skipparsedbodiesinsession");
lua_setfield(L, -2,"IndexOptFlags");

lua_newtable(L);
lua_pushinteger(L, 0);
lua_setfield(L, -2, "Success");
lua_pushinteger(L, 1);
lua_setfield(L, -2, "Failure");
lua_pushinteger(L, 2);
lua_setfield(L, -2, "Crashed");
lua_pushinteger(L, 3);
lua_setfield(L, -2, "Invalidarguments");
lua_pushinteger(L, 4);
lua_setfield(L, -2, "Astreaderror");
lua_setfield(L, -2,"ErrorCode");

}

int luaopen_clangc_constants(lua_State *L)
{
  lua_newtable(L); //create the main module table
/*
* Create the clangc constants
*/
  init_clang_enums_to_constants(L);
  return 1; //return the table
}
