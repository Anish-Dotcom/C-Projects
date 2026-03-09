#include <iostream>
#include "binarytree.h"

treenode::treenode(int inum) {data = inum;}
treenode::~treenode(){}
int treenode::getdata() {return data;}
treenode* treenode::getleft() {return left;}
treenode* treenode::getright() {return right;}
void treenode::setleft(treenode* newleft) {left = newleft;}
void treenode::setright(treenode* newright) {right = newright;}
