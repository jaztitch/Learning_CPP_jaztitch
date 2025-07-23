#include <iostream>
#include <string>
#include "structures.hpp"

using namespace std;

string input;

stdObj *addNewObj(stdObj *obj, string name, string color, string material, string status){
        stdObj *o=obj;
    
    if(o==NULL){
        o=(struct stdObj*) malloc(sizeof(stdObj));
        o->name = name;
        o->color = color;
        o->material = material;
        o->status = status;
        o->next = NULL;
        return(o);
    }
    else{while(o->next!=NULL){o=o->next;}

    o->next = (struct stdObj*) malloc(sizeof(stdObj));
    o->next->name=name;
    o->next->color=color;
    o->next->material=material;
    o->next->status=status;
    o->next->next=NULL;
    return(o->next);
    }
};

void setupMap(void)
{
	stdObj *obj;
 
	// world 0,0 EAST
	world[0][0].east.created = true;
	world[0][0].east.info = "There is a window showing a big tree";
	obj = addNewObj( world[0][0].east.objects, "window", "white", "wooden", "dirty");
	obj = addNewObj( world[0][0].east.objects, "tree", "green", "", "big");
 
	// world 0,0 WEST
	world[0][0].west.created = true;
	world[0][0].west.info = "Door here !";
	obj = addNewObj( world[0][0].west.objects, "door", "black", "metal", "very rusty");
 
	// world 0,0 CENTER
	world[0][0].center.created = true;
	world[0][0].center.info = " I can't move to the center, table here !";
	obj = addNewObj( world[0][0].center.objects, "door", "black", "metal", "very rusty");
}

int main(){

    return 0;
}