/*Esin Ece Aydin 150160151 
*/

#include<stdio.h> //printf & scanf
#include<stdlib.h> // EXIT_SUCCESS

/*
 * Compute the value of corresponding to throw
 * @param segment the segment of throw
 * @param ring the ring of throw
  * @return the point value.
 */
int point_valueThrow(int segment, char ring ){
    int point_value = 0;
    
    switch(ring){
        case 'D':
            point_value = segment * 2;
            break;
        case 'T':
            point_value = segment * 3;
            break;
        case 'S':
            point_value = segment;
            break;    
        case 'O':
            point_value = 25;
            break;
        case 'I':
            point_value = 50;
            break;
    }
    
    return point_value;
}

/*
 * Compute the remaining value after that throw according to the rules describe in assignment
 * @param current_point the segment of throw
 * @param segment the segment of throw
 * @param ring the ring of throw
 * @param target game's target value
  * @return the remaining value.
 */
int big_boss(int current_point, int segment, char ring, int target){
    int remaining_point;
    
    if(current_point == target){
        if(ring != 'D'){
            remaining_point = current_point;
        }else 
            remaining_point = current_point - point_valueThrow(segment, ring);
    }else{     
            remaining_point = current_point - point_valueThrow(segment, ring);
    }
    
        
    if(remaining_point < 0){
        remaining_point = current_point;
    }else if(remaining_point == 0){
        if(ring != 'D'){
            remaining_point = current_point;
        }else
            remaining_point = 0;
    }
    
 
    return remaining_point;
}

int main(){
    int target;
    int segment;
    char ring;
    int current_point; 


    
    printf("Target: ");
    scanf("%d", &target);
    
    printf("\n");
    
    current_point = target;
    while(current_point > 0){
        printf("Throw: ");
        scanf("%d %c", &segment, &ring);
        current_point = big_boss(current_point, segment, ring, target); 
        printf("Points: %d\n", current_point);
    }
    
    
       
    return EXIT_SUCCESS;
}










