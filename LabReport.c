#include <stdio.h> 
#define MAX 100 

// structure to hold x and y coordinates and mass 
struct cg {
    float x;
    float y;
    float mass; 
};

// creates the array
struct cg masses[MAX]; 

int readin(void)
{ 
  // define variables we will use
  int n_masses;

  // ask for how many weights we will have
  printf("Enter number of weights: ");
  if (scanf("%d", &n_masses) != 1) { // Validate input
      printf("Invalid input. Please enter a number.\n");
      return 0;
  }

  // create a loop to get the info for each weight
  int i = 0;
  while (i < n_masses) {
    // ask for the x, y and mass of each weight
    printf("Enter x, y, mass: ");
    // if statment prevents incorrect inputs
    // each input is put directly into the array
    if(scanf("%f %f %f", 
        &masses[i].x,
        &masses[i].y,
        &masses[i].mass) != 3) {
      printf("Invalid input format.\n");
      return 0; // Exit with error
      };
    i++;
    } 
};

// function will call apon the array and then use said data to output average
void computecg(int n_masses)
{
  // define variables we will use
  float sum_of_xmass = 0;
  float sum_of_ymass = 0;
  float sum_of_mass = 0;

  // find sum of all x mass, sum of y mass, and sum of all masses
  for (int i = 0; i < n_masses; i++) {
    sum_of_xmass = sum_of_xmass + (masses[i].x * masses[i].mass);
    sum_of_ymass = sum_of_ymass + (masses[i].y * masses[i].mass);
    sum_of_mass = sum_of_mass + masses[i].mass;
  }

  // calculate the center of gravity
  float cg_x = sum_of_xmass / sum_of_mass;
  float cg_y = sum_of_ymass / sum_of_mass;

  // output the center of gravity
  printf("Center of Gravity: (%f, %f)\n", cg_x, cg_y);

};


int main(void)
{
  int number; 
  if((number = readin()) > 0) 
    computecg(number); 
  return 0; 
};

