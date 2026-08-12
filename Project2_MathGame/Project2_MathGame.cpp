#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
enum enLevels { Easy = 1, Medium = 2, Hard = 3 , Mixed = 4 };
enum enOperations { Addition = 1, Subtraction = 2, Multiplication = 3, Division = 4, Mix = 5 };	
int ReadNumberInRange(int From, int To)
{
	int Number;

	cin >> Number;

	while (Number < From || Number > To)
	{
		cout << "Invalid number. Enter a number between "
			<< From << " and " << To << ": ";

		cin >> Number;
	}

	return Number;
}
struct stQuizz {
	enLevels Level = enLevels::Easy;
	enOperations Operation = enOperations::Addition ;
	int QuestionNumber =0;
	int CorrectAnswers = 0;
	int IncorrectAnswers = 0;
};
enLevels ReadLevel() {
	int level;
	cout << "Enter the Questionslevel of difficulty [1] Easy, [2] Medium, [3] Hard, [4] Mixed: ";
	 level = ReadNumberInRange(0,4);
	return (enLevels)level;
}
enOperations ReadOperation() {
	int operation;
	cout << "Enter the operation you want to practice [1] Addition, [2] Subtraction, [3] Multiplication, [4] Division, [5] Mixed: ";
 operation = ReadNumberInRange(0,5);
	return (enOperations)operation;
}
int RandomNum(int min, int max)
{
	return rand() % (max - min + 1) + min;
}
int ReadQuestionNumber() {
	int questionNumber;
	cout << "Enter the number of questions you want to answer: ";
	cin >> questionNumber;
	return questionNumber;
	}
char OperationToChar(enOperations operation)
{
	switch (operation)
	{
	case enOperations::Addition:
		return '+';

	case	enOperations::Subtraction:
		return '-';

	case enOperations::Multiplication:
		return '*';

	case enOperations::Division:
		return '/';


	}
}
void CheckAnswer(int num1, int num2, int Answer, enOperations operation, stQuizz& quizz) {
	int correctAnswer;
	switch (operation) {
	case enOperations::Addition:
		correctAnswer = num1 + num2;
		break;
	case enOperations::Subtraction:
		correctAnswer = num1 - num2;
		break;
	case enOperations::Multiplication:
		correctAnswer = num1 * num2;
		break;
	case enOperations::Division:
		correctAnswer = num1 / num2;
		break;
	}
	if (Answer == correctAnswer) {
		cout << "Correct!" << endl;
		system("color 0A");
		quizz.CorrectAnswers++;
	}
	else {
		cout << "Incorrect. The correct answer is: " << correctAnswer << endl;
		system("color 0C");
		quizz.IncorrectAnswers++;
	}
}



void AskQuestionDependOnLevel(stQuizz& quizz) {

	int num1, num2, Answer, Num1, Num2;
	enLevels currentLevel = quizz.Level;
	enOperations currentOperation = quizz.Operation;
	if (currentOperation == enOperations::Mix)
	{
		currentOperation = (enOperations)RandomNum(1, 4);
	}
	if (currentLevel == enLevels::Mixed)
	{
		currentLevel = (enLevels)RandomNum(1, 3);
	}

	if (currentLevel == enLevels::Easy)
	{
		Num1 = 1;
		Num2 = 10;
	}
	else if (currentLevel == enLevels::Medium)
	{
		Num1 = 10;
		Num2 = 100;
	}
	else if (currentLevel == enLevels::Hard)
	{
		Num1 = 1;
		Num2 = 1000;
	}

	num1 = RandomNum(Num1, Num2);
	num2 = RandomNum(Num1, Num2);

	cout << num1 << endl;
	cout << OperationToChar(currentOperation) << endl;
	cout << num2 << endl;
	cout << "========================================" << endl;

	cin >> Answer;

	CheckAnswer(num1, num2, Answer, currentOperation, quizz);
	}


void ShowGameResults(stQuizz& quizz) {
	cout << "Game Results:" << endl;
	cout << "Total Questions: " << quizz.QuestionNumber << endl;
	cout << "Correct Answers: " << quizz.CorrectAnswers << endl;
	cout << "Incorrect Answers: " << quizz.IncorrectAnswers << endl;
	if (quizz.CorrectAnswers > quizz.IncorrectAnswers) {
		cout << "You are a Math Genius!" << endl;
		system("color 0A");
	}
	else if (quizz.CorrectAnswers == quizz.IncorrectAnswers) {
		cout << "You are a Math Average!" << endl;
		system("color 0E");
	}
	else {
		cout << "You need to practice more!" << endl;
		system("color 0C");
	}
}


void StartGame(stQuizz& quizz) {
	quizz.CorrectAnswers = 0;
	quizz.IncorrectAnswers = 0;
	quizz.QuestionNumber = ReadQuestionNumber();
	quizz.Level = ReadLevel();
	quizz.Operation = ReadOperation();
	for (int i = 0; i <quizz.QuestionNumber ; i++) {
		AskQuestionDependOnLevel(quizz);
	}
	ShowGameResults(quizz);
	
}

void AskPlayAgain(stQuizz& quizz) {
	char playAgain;
	cout << "Do you want to play again? (Y/N): ";
	cin >> playAgain;
	while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n') {
		cout << "Invalid input. Please enter Y or N: ";
		cin >> playAgain;
	}
	while (playAgain == 'Y' || playAgain == 'y') {

		system("cls");
		system("color 0F");

		StartGame(quizz);

		cout << "Do you want to play again? (Y/N): ";
		cin >> playAgain;

		while (playAgain != 'Y' && playAgain != 'y' &&
			playAgain != 'N' && playAgain != 'n') {
			cout << "Invalid input. Please enter Y or N: ";
			cin >> playAgain;
		}
	}
}
int main() {
	srand((unsigned)time(NULL));
	stQuizz quizz;
	StartGame(quizz);
	AskPlayAgain(quizz);
}

