#ifndef QUERRYSTRING_H
#define QUERRYSTRING_H


#endif // !QUERRYSTRING_H

//CREATE TABLE testPassed(
//	num Integer NOT NULL PRIMARY KEY AUTOINCREMENT, 
//	users_id Integer NOT NULL, 
//	groupNum Integer NOT NULL, 
//	subGroupNum Integer NOT NULL, 
//	testNum Integer NOT NULL, 
//	countAnswers Integer, 
//	countRightAns Integer, 
//	countTry Integer, 
//	passed Boolean NOT NULL, 
//	CONSTRAINT lnk_users_testPassed FOREIGN KEY(users_id) REFERENCES users(id) ON DELETE CASCADE ON UPDATE CASCADE, 
//	CONSTRAINT lnk_testPassed_tableGroupsTests FOREIGN KEY(groupNum) REFERENCES tableGroupsTests(idGrTest), 
//	CONSTRAINT lnk_testPassed_mathematics FOREIGN KEY(subGroupNum) REFERENCES mathematics(numGrTest), 
//	CONSTRAINT lnk_testPassed_physics FOREIGN KEY(subGroupNum) REFERENCES physics(numGrTest), 
//	CONSTRAINT lnk_testPassed_mathDiscrete FOREIGN KEY(testNum) REFERENCES mathDiscrete(numTest), 
//	CONSTRAINT lnk_testPassed_mathAnalysis FOREIGN KEY(testNum) REFERENCES mathAnalysis(numTest), 
//	CONSTRAINT lnk_testPassed_phisicsQuant FOREIGN KEY(testNum) REFERENCES phisicsQuant(numTest), 
//	CONSTRAINT lnk_testPassed_phisicsMech FOREIGN KEY(testNum) REFERENCES phisicsMech(numTest), 
//	CONSTRAINT unique_num UNIQUE(num))

/*---tableGroups----*/
//CREATE TABLE IF NOT EXISTS tableGroupsTests(
//	idGrTest Integer NOT NULL PRIMARY KEY AUTOINCREMENT,
//	nameGroup TEXT CONSTRAINT "nameGroup<>''" NOT NULL,
//	countTest Integer NOT NULL,
//	tableName TEXT NOT NULL,
//	CONSTRAINT unique_tableName UNIQUE(tableName),
//	CONSTRAINT unique_idGrTest UNIQUE(idGrTest))

/*---tableGroup---*/
//CREATE TABLE IF NOT EXISTS physics(
//	numGrTest Integer NOT NULL PRIMARY KEY AUTOINCREMENT, 
//	nameGroupTest Text NOT NULL, 
//	tableGroupTest Text NOT NULL, 
//	CONSTRAINT unique_numGrTest UNIQUE(numGrTest), 
//	CONSTRAINT unique_tableGroupTest UNIQUE(tableGroupTest))

/*---tableSubGroup----*/
//CREATE TABLE IF NOT EXISTS phisicsQuant(
//	numTest Integer NOT NULL PRIMARY KEY AUTOINCREMENT, 
//	nameTest Text, 
//	tableNameTest Text NOT NULL, 
//	countQuestions Integer NOT NULL, 
//	CONSTRAINT unique_tableNameTest UNIQUE(tableNameTest))

/*---tableTest---*/
//CREATE TABLE IF NOT EXISTS phisicsMech0001(
//	numQ Integer NOT NULL PRIMARY KEY AUTOINCREMENT, 
//	question Text, 
//	answer01 Text, 
//	answer02 Text, 
//	answer03 Text, 
//	answer04 Text, 
//	rightAnswer Integer)
