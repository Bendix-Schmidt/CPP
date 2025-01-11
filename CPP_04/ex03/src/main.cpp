/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:14:26 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/11 18:47:28 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

	void	testCloning()
{
	Ice ice;
	AMateria* clonedIce = ice.clone();
	std::cout << "Cloned Materia type: " << clonedIce->get_type() << std::endl;
}

void	testInventoryLimits(ICharacter* character, IMateriaSource *src)
{
	AMateria *tmp;

	tmp = src->createMateria("ice");
	character->equip(tmp);
	tmp = src->createMateria("cure");
	character->equip(tmp);
	tmp = src->createMateria("ice");
	character->equip(tmp);
	tmp = src->createMateria("cure");
	character->equip(tmp);
	std::cout << "Attempting to equip more than 4 Materia:" << std::endl;
	//character->equip(ice); // Should not equip
}

void	testUnequip(ICharacter* character)
{
	//character->unequip(0);
	std::cout << "Unequipped Materia from slot 0." << std::endl;
	character->use(0, *character);  // Should not use anything
}

void	testInvalidUse(ICharacter* character)
{
	std::cout << "Attempting to use Materia from an empty slot:" << std::endl;
	character->use(0, *character);  // Should not do anything
}

void	testDeepCopy()
{
	Character original("original");
	AMateria* ice = new Ice();
	original.equip(ice);

	Character copy = original;  // Using copy constructor
	std::cout << "Using Materia from copied character:" << std::endl;
	copy.use(0, original);
	delete ice;
}

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");
	
	me->equip(ice);
	me->equip(cure);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	testCloning();
	testInventoryLimits(me, src);
	std::cout << "TEST1" << std::endl;
	testUnequip(me);
	std::cout << "TEST2" << std::endl;
	testInvalidUse(me);
	testDeepCopy();

	delete bob;
	std::cout << "TEST3" << std::endl;
	delete me;
	std::cout << "TEST4" << std::endl;
	delete src;
	
	std::cout << "--------- SUBJECT TEST ---------"<< std::endl;

	{
		IMateriaSource*	src = new MateriaSource();
		AMateria*		tmp;
		ICharacter*		me = new Character("me");
		ICharacter*		bob = new Character("bob");

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << std::endl << "------------ TEST 1 ------------"<< std::endl;

	{
		MateriaSource*	materiaMaker = new MateriaSource();
		ICharacter*		bob = new Character("bob");
		Character		ned("Ned");
		MateriaSource	stackMaker;

		materiaMaker->learnMateria(new Ice());
		materiaMaker->learnMateria(new Cure());
		materiaMaker->learnMateria(new Ice());
		materiaMaker->learnMateria(new Cure());
		materiaMaker->learnMateria(new Cure());

		stackMaker.learnMateria(new Ice());
		stackMaker.learnMateria(new Cure());
		stackMaker.learnMateria(new Ice());
		stackMaker.learnMateria(new Cure());
		stackMaker.learnMateria(new Cure());

		//bob->printInventory();
		bob->equip(materiaMaker->createMateria("non"));
		bob->equip(materiaMaker->createMateria("ice"));
		bob->equip(materiaMaker->createMateria("cure"));
		bob->equip(materiaMaker->createMateria("ice"));
		bob->equip(materiaMaker->createMateria("cure"));
		bob->equip(materiaMaker->createMateria("ice"));
		ned.equip(stackMaker.createMateria("non"));
		ned.equip(stackMaker.createMateria("ice"));
		ned.equip(stackMaker.createMateria("cure"));
		ned.equip(stackMaker.createMateria("ice"));
		ned.equip(stackMaker.createMateria("cure"));
		ned.equip(stackMaker.createMateria("ice"));
		bob->use(-1, ned);
		bob->use(0, ned);
		bob->use(1, ned);
		bob->use(2, ned);
		bob->use(3, ned);
		bob->use(4, ned);
		bob->use(5, ned);
		ned.use(-1, *bob);
		ned.use(0, *bob);
		ned.use(1, *bob);
		ned.use(2, *bob);
		ned.use(3, *bob);
		ned.use(4, *bob);
		ned.use(5, *bob);

		bob->unequip(-1);
		bob->unequip(0);
		bob->unequip(1);
		bob->unequip(2);
		bob->unequip(3);
		bob->unequip(4);
		bob->unequip(5);
		ned.unequip(-1);
		ned.unequip(0);
		ned.unequip(1);
		ned.unequip(2);
		ned.unequip(3);
		ned.unequip(4);
		
		delete bob;
		delete materiaMaker;
	}

	return (0);
}