#include "tddFuncs.h"
#include "WordCount.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Testing WordCount.cpp..." << endl;
    
    WordCount colors;
    std::string word = "green";
    char C = 'A';
    char c = 'a';
    char notC = '?';
    char apos = '\'';

    cout << "Testing empty WordCount..." << endl;
    assertEquals(0, colors.getTotalWords(), "colors.getTotalWords()", 17);
    assertEquals(0, colors.getNumUniqueWords(), "colors.getNumUniqueWords()", 18);
    assertEquals(0, colors.getWordCount(word), "colors.getWordCount(word)", 19);
    cout << endl;

    cout << "Testing isWordChar(char c)..." << endl;
    assertTrue(colors.isWordChar(c), "colors.isWordChar(c)", 23);
    assertTrue(colors.isWordChar(C), "colors.isWordChar(C)", 24);
    assertEquals(false, colors.isWordChar(notC), "colors.isWordChar(notC)", 25);
    assertEquals(false, colors.isWordChar(apos), "colors.isWordChar(apos)", 26);
    cout << endl;

    cout << "Testing makeValidWord(const std::string & word)..." << endl;
    assertEquals("green", colors.makeValidWord("gre3e3n"), "colors.makeValidWord(\"gre3e3n\")", 30);
    assertEquals("red", colors.makeValidWord("RED"), "colors.makeValidWord(\"RED\")", 31);
    assertEquals("blue", colors.makeValidWord("'bLue3-*"), "colors.makeValidWord(\"\'bLue3-*\")", 32);
    assertEquals("good-hearted", colors.makeValidWord("good-hearted"), "colors.makeValidWord(\"good-hearted\")", 33);
    assertEquals("lol'-'gottem", colors.makeValidWord("lol'-'gottem"), "colors.makeValidWord(\"lol'-'gottem\")", 34);
    assertEquals("abcdf-'q", colors.makeValidWord("aBcD3F-'$q--"), "colors.makeValidWord(\"aBcD3F-\'$q--\")", 35);
    assertEquals("", colors.makeValidWord("--$$--"), "colors.makeValidWord(\"--$$--\")", 36);
    cout << endl;

    cout << "Testing incrWordCount(const std::string & word)..." << endl;
    
    assertEquals(0, colors.incrWordCount("--$$--"), "colors.incrWordCount(\"--$$--\")", 40);
    
    colors.incrWordCount("green");
    assertEquals(1, colors.getTotalWords(), "colors.getTotalWords()", 40);
    assertEquals(1, colors.getNumUniqueWords(), "colors.getNumUniqueWords()", 41);
    assertEquals(1, colors.getWordCount("green"), "colors.getWordCount(\"green\")", 42);
    
    for(int i = 0; i < 9; i++){
        colors.incrWordCount("green");
    }
    assertEquals(10, colors.getTotalWords(), "colors.getTotalWords()", 47);
    assertEquals(1, colors.getNumUniqueWords(), "colors.getNumUniqueWords()", 48);
    assertEquals(10, colors.getWordCount("green"), "colors.getWordCount(\"green\")", 49);

    colors.incrWordCount("re3d");
    colors.incrWordCount("RED");
    colors.incrWordCount("red-");

    assertEquals(13, colors.getTotalWords(), "colors.getTotalWords()", 55);
    assertEquals(2, colors.getNumUniqueWords(), "colors.getNumUniqueWords()", 56);
    assertEquals(3, colors.getWordCount("red"), "colors.getWordCount(\"red\")", 57);

    colors.incrWordCount(""); 

    assertEquals(13, colors.getTotalWords(), "colors.getTotalWords()", 61);
    assertEquals(2, colors.getNumUniqueWords(), "colors.getNumUniqueWords()", 62);
    assertEquals(0, colors.getWordCount(""), "colors.getWordCount(\"\")", 63);
    cout << endl;

    cout << "Testing decrWordCount(const std::string & word)..." << endl;

    for(int j = 0; j < 5; j++){
        colors.decrWordCount("green");
    }

    assertEquals(8, colors.getTotalWords(), "colors.getTotalWords()", 72);
    assertEquals(2, colors.getNumUniqueWords(), "colors.getNumUniqueWords()", 73);
    assertEquals(5, colors.getWordCount("green"), "colors.getWordCount(\"green\")", 74);

    for(int k = 0; k < 5; k++){
        colors.decrWordCount("re3d");
    }

    assertEquals(5, colors.getTotalWords(), "colors.getTotalWords()", 80);
    assertEquals(1, colors.getNumUniqueWords(), "colors.getNumUniqueWords()", 81);
    assertEquals(0, colors.getWordCount("red"), "colors.getWordCount(\"red\")", 82);

    assertEquals(4, colors.decrWordCount("green"), "decrWordCount(\"green\")", 84);
    assertEquals(-1, colors.decrWordCount("blue"), "decrWordCount(\"blue\")", 85);

    return 0;
}