/*
 * Quetions.h
 *
 * Created: 17-Mar-16 11:23:03 PM
 *  Author: LENOVO
 */ 


#ifndef QUETIONS_H_
#define QUETIONS_H_
#include "StdTypes.h"
#define QUESTIONS_NUMBER 22
typedef struct
{
	char ques[11] ;
	int ans ;
	}Question;

extern Question QuestionList[QUESTIONS_NUMBER] ;


#endif /* QUETIONS_H_ */