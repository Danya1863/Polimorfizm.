#pragma once
#include <iostream>
#include "Header.h"

using namespace std;
using namespace Military;

namespace Transport
{
	class Vehicle
	{
	protected:
		double Benzin;
		double tank;
	public:
		Vehicle()
		{
			Benzin = 0;
			tank = 0;
		}
		Vehicle(double petrol_amount, double tank_volume)
		{
			Benzin = petrol_amount;
			tank = tank_volume;
		}
		double getTankVolume()
		{
			return tank;
		}
		double getBenzinAmount()
		{
			return Benzin;
		}
		void setPatrolAmount(double a)
		{
			Benzin = a;
		}
		virtual void arrive(Base& a)
		{
			setPatrolAmount(getBenzinAmount() - 30);
			a.SetVehicles(a.GetVehicles() + 1);
			a.SetPeople(a.GetPeople() + 1);
		}
		virtual bool leave(Base& a)
		{
			if (a.GetPetrol() > 0)
			{
				int temp = getTankVolume() - getBenzinAmount();
				if (temp >= a.GetPetrol())
				{
					setPatrolAmount(getBenzinAmount() + a.GetPetrol());
					a.SetPetrol(0);
				}
				else
				{
					setPatrolAmount(getBenzinAmount() + temp);
					a.SetPetrol(a.GetPetrol() - temp);
				}
			}
			if (getBenzinAmount() >= 30 && a.GetPeople() >= 1)
			{
				a.SetVehicles(a.GetVehicles() - 1);
				a.SetPeople(a.GetPeople() - 1);
				return true;
			}
			else
				return false;
		}
		virtual void Print()
		{
			cout << "Benzin: " << Benzin << endl;
			cout << "Ob'em: " << tank << endl;
		}
	};

	class Bus :public Vehicle
	{
		int passanger;
		int max_passanger;
	public:
		Bus(int people, int max_people, double petrol, double max_petrol) :Vehicle(petrol, max_petrol)
		{
			passanger = people;
			max_passanger = max_people;
		}
		int getPeopleCount()
		{
			return passanger;
		}
		int getMaxPeople()
		{
			return max_passanger;
		}
		void setPeopleCount(int a)
		{
			passanger = a;
		}
		void setMaxPeople(int a)
		{
			max_passanger = a;
		}
		void arrive(Base& a)
		{
			Vehicle::arrive(a);
			a.SetPeople(a.GetPeople() + getPeopleCount());
			setPeopleCount(0);
		}
		bool leave(Base& a)
		{
			if (Vehicle::leave(a))
			{
				if (a.GetPeople() > 0)
				{
					int temp = getMaxPeople() - getPeopleCount();
					if (temp >= a.GetPeople())
					{
						setPeopleCount(getPeopleCount() + a.GetPeople());
						a.SetPeople(0);
					}
					else
					{
						setPeopleCount(getPeopleCount() + temp);
						a.SetPeople(a.GetPeople() - temp);
					}
					return true;
				}
				else
					return false;
			}
		}
		void Print()
		{
			Vehicle::Print();
			cout << "Men: " << passanger << endl;
			cout << "Maximum Men: " << max_passanger << endl;
		}
	};

	class Truck :public Vehicle
	{
		double loaded;
		double max_loaded;
	public:
		Truck(double load, double max_load, double petrol, double max_petrol) :Vehicle(petrol, max_petrol)
		{
			loaded = load;
			max_loaded = max_load;
		}
		double getCurrentLoad()
		{
			return loaded;
		}
		double getMaxLoad()
		{
			return max_loaded;
		}
		void setCurrentLoad(int a)
		{
			loaded = a;
		}
		void arrive(Base& a)
		{
			Vehicle::arrive(a);
			a.SetGoods(a.GetGoods() + getCurrentLoad());
			setCurrentLoad(0);
		}
		bool leave(Base& a)
		{
			if (Vehicle::leave(a))
			{
				if (a.GetGoods() > 0)
				{
					int temp = getMaxLoad() - getCurrentLoad();
					if (temp >= a.GetGoods())
					{
						setCurrentLoad(getCurrentLoad() + a.GetGoods());
						a.SetGoods(0);
					}
					else
					{
						setCurrentLoad(getCurrentLoad() + temp);
						a.SetGoods(a.GetGoods() - temp);
					}
					return true;
				}
				else
					return false;
			}
		}
		void Print()
		{
			Vehicle::Print();
			cout << "Zagruzka: " << loaded << " t\n";
			cout << "max Zagruzka: " << max_loaded << " t\n";
		}
	};
}