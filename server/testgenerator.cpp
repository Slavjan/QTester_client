#include "testgenerator.h" 

Profession TestGenerator::collectTestVariant( const SQLMgr &base,
                                                     const ParamsForCollection &params )
{
    Profession prof;
    prof.setId( params.professionId );

    idThemeIdsMap less_them_ids;
    less_them_ids[params.lessIds] = params.themsIds;

    prof.selectLessonsFromDatabase( base, less_them_ids, params.questionsCount, params.answersCount );
		
	return prof;
}


/*	TODO List
	* сделать выборку вопросов, тем самым сгенерировать вариант теста
	** выбераем вопросы пишем в StringList
	** выбераем ответы пишем в другой StringList
	** записываем в QMap 
			  ^
	Tester эти^ методы пользует, получает собственно вариант теста и выдает вопросы по требованию	
*/