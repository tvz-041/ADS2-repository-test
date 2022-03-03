// Trees.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <chrono>
#include <iostream>

#include "BinaryTree.h"

int main()
{
	const int runsCount = 1000;
	const int treeSize = 500;
	const int measureStartIndex = 0;
	const int measureCount = treeSize;

	int nonRecursiveWins = 0;
	int recursiveWins = 0;

	auto nonRecursiveWinsTimeSum = std::chrono::steady_clock::duration::zero();
	auto recursiveWinsTimeSum = std::chrono::steady_clock::duration::zero();

	auto nonRecursiveTimeSum = std::chrono::steady_clock::duration::zero();
	auto recursiveTimeSum = std::chrono::steady_clock::duration::zero();

	for (int k = 0; k < runsCount; ++k) {
		BinaryTree bt;

		for (int i = 0; i < treeSize; i++)
			bt.addNode(bt.getRoot(), i);

		auto start = std::chrono::steady_clock::now();
		for (int i = measureStartIndex; i < measureCount; i++) {
			bt.node(i);
		}
		auto stop = std::chrono::steady_clock::now();
		auto nonRecursiveTime = (stop - start);
		nonRecursiveTimeSum += nonRecursiveTime;

		start = std::chrono::steady_clock::now();
		for (int i = measureStartIndex; i < measureCount; i++) {
			bt.nodeRecursive(i);
		}
		stop = std::chrono::steady_clock::now();
		auto recursiveTime = (stop - start);
		recursiveTimeSum += recursiveTime;

		if (nonRecursiveTime > recursiveTime) {
			recursiveWins++;
			recursiveWinsTimeSum += (nonRecursiveTime - recursiveTime);
		} else if (nonRecursiveTime < recursiveTime) {
			nonRecursiveWins++;
			nonRecursiveWinsTimeSum += (recursiveTime - nonRecursiveTime);
		}
	}

	std::cout << "non-recursive average time (ms): " << std::chrono::duration<double, std::milli>(nonRecursiveTimeSum).count() / runsCount << std::endl;
	std::cout << "recursive average time (ms): " << std::chrono::duration<double, std::milli>(recursiveTimeSum).count() / runsCount << std::endl;
	std::cout << "non-recursive method wins: " << nonRecursiveWins << std::endl;
	std::cout << "recursive method wins: " << recursiveWins << std::endl;
	std::cout << "average non-recursive time advantage (ms): " << std::chrono::duration<double, std::milli>(nonRecursiveWinsTimeSum).count() / (nonRecursiveWins ? nonRecursiveWins : 1) << std::endl;
	std::cout << "average recursive time advantage (ms): " << std::chrono::duration<double, std::milli>(recursiveWinsTimeSum).count() / (recursiveWins ? recursiveWins : 1) << std::endl;

	//BinaryTree bt;
	//for (int i = 0; i < count; i++)
	//	bt.addNode(bt.getRoot(), i);
	//bt.printHorizontal();
	//std::cout << std::endl << std::endl << std::endl;
	//for (int i = 0; i < 10; i++) {
	//	bt.printLevel(i);
	//	std::cout << std::endl;
	//}

	//for (int i = 0; i < count; i++) {
	//	std::cout << (bt.node(i) ? bt.node(i)->key : -1) << "	"
	//			  << (bt.nodeRecursive(i) ? bt.nodeRecursive(i)->key : -1) << std::endl;
	//}

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
