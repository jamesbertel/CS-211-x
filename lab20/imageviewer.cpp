#include <iostream>
#include <fstream>
#include "imageviewer.h"
using namespace std;

/************

CONSTRUCTOR

************/
ImageViewer::ImageViewer()
{
  head = NULL;
  current = new Image("", 0.0, "", "");
}

/*****************

FUNCTIONS

****************/

/******
This function creates a new Image and initializes its data to iName, iSize, iFormat, and iResolution.
The function then inserts the new Image into the list while maintaining the list order.
*******/
void ImageViewer::addImage(string iName, double iSize, string iFormat, string iResolution)
{
  Image *newnode;
  Image *nodeptr;

  newnode = new Image(iName, iSize, iFormat, iResolution);

  if(!head)
    {
      head = newnode;
    }
  else
    {
      //put nodeptr at head of list
      nodeptr = head;
      
      //check to see if node belongs in head
      if(nodeptr->name > iName)
	{
	  newnode->next = head;
	  head->previous = newnode;
	  head = newnode;
	  newnode->previous = NULL;
	}
      else
	{
	  while(nodeptr != NULL)// && nodeptr->name < iName)
	    {
	      if(nodeptr->name > iName)
		{ 
		  //insert pointer
		  newnode->previous = nodeptr->previous->previous;
		  newnode->next = nodeptr;
		  nodeptr->previous = newnode;
		  nodeptr = NULL;
		}	  
	      else
		{
		  //move pointer forward
		  nodeptr->previous = nodeptr;
		  nodeptr = nodeptr->next;
		}
	    }
	}
    }
  newnode = NULL;
}

/*****
This function views the current image
*****/
void ImageViewer::viewImage(string iName)
{
  string fName = "C:/Users/Mayssaa/CS211/HW4/"; //beginning of name

  current->next = head;
  current = current->next;

  fName.append(iName); //puts entire file name together

  while(current != NULL)
    {
      if(current->name == fName)
        {
          cout << current->name << ".";
          cout << current->format << ", ";
          cout << current->size << ", ";
          cout << current->resolution << endl;
          break;
        }
      else
        {
          current = current->next;
        }
    }
  cout << endl;
}

/*****
This function views the next image
*****/
void ImageViewer::viewNextImage()
{
  current = current->next;

  cout << current->name << ".";
  cout << current->format << ", ";
  cout << current->size << ", ";
  cout << current->resolution << endl;
  cout << current->previous->name << endl;
}

/****
This function updates the current pointer to point to the previous image
****/
void ImageViewer::viewPreviousImage()
{
  current = current->previous->previous;

  cout << current->name << ".";
  cout << current->format << ", ";
  cout << current->size << ", ";
  cout << current->resolution << endl;
}

/*****
This function deletes the current image
*****/
void ImageViewer::deleteCurrentImage()
{
  delete current;
  current = current->next;
}

/****
This function compresses the current image
*****/
void ImageViewer::compressCurrentImage(double ratio)
{
  current->size = current->size * ratio;
}

/*****
This function displays the data of each image in the list.
*****/
void ImageViewer::slideshow()
{
  Image * p = new Image;
  p->next = head;
  p = p->next;
  cout << endl;

  while(p != NULL)
    {
      cout << p->name << ".";
      cout << p->format << ", ";
      cout << p->size << ", ";
      cout << p->resolution << endl;
      
      p = p->next;
    }

  cout << endl;  
}

/*****
This function displace the data of each image in reverse order.
*****/
void ImageViewer::reverseSlideshow()
{
  Image * p = new Image;
  p->next = head;
  p = p->next;
  cout << endl;

  while(p != NULL)
    {
      p->previous = p;
      p = p->next;
      cout << p->name << endl;
    }

  //p = p->previous;
  //p->next = NULL;

  while(p != NULL)
    {
      cout << p->name << ".";
      cout << p->format << ", ";
      cout << p->size << ", ";
      cout << p->resolution << endl;

      p = p->previous;
    }
  cout << endl;
}

/**********
This function processes the transaction file
***********/
void ImageViewer::processTransactionFile()
{
  ifstream fin;
  string operation; //variable for commands such as "add", "display", "search", etc                  
  string name; //name of image
  double size; //size
  string format; //photo format
  string res; //photo resolution

  fin.open("image.txt");

  if(!fin)
    cout << "Error: file DNE" << endl;
  else
    {
      fin >> operation; //put first command into operation                                            
      while(fin)
        { //call proper function based on command                                                     
          if(operation=="addImage")
	    {
	      fin >> name;
	      fin >> size;
	      fin >> format;
	      fin >> res;
	      addImage(name, size, format, res);
	    }
          else if(operation=="slideshow")
            slideshow();
          else if(operation=="viewImage")
	    {
	      fin >> name;
	      viewImage(name);
	    }
          else if(operation=="viewNextImage")
            viewNextImage();
          else if(operation=="viewPreviousImage")
            viewPreviousImage();
          else if(operation=="compressCurrentImage")
            {
	      fin >> size;
	      compressCurrentImage(size);
	    }
          else if(operation=="deleteCurrentImage")
            deleteCurrentImage();
          else if(operation=="reverseSlideshow")
            reverseSlideshow();
          else
            {cout << "ERROR: NO COMMAND. CHECK FILE." << endl; break;}

          fin >> operation; //puts "add", "display", "search", etc into operation                     
        }
    }

  cout << endl;
  fin.close();
}
