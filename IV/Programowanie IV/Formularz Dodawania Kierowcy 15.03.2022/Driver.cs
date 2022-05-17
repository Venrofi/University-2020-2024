using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Formularz_Dodawania_Kierowcy
{
    class Driver
    {
        private string _firstName;
        private string _lastName;
        private int _weight;
        private int _age;

        public Driver(string firstName, string lastName, int weight, int age)
        {
            this._firstName = firstName;
            this._lastName = lastName;
            this._weight = weight;
            this._age = age;
        }

        public Driver()
        {
            this._firstName = "";
            this._lastName = "";
            this._weight = 0;
            this._age = 0;
        }

        public override string ToString()
        {
            return $"{_firstName}, {_lastName}, {_age} lat, {_weight} kg";
        }

        public string firstName
        {
            get { return _firstName; }
            set { _firstName = value; }
        }

        public string lastName
        {
            get { return _lastName; }
            set { _lastName = value; }
        }

        public int weight
        {
            get { return _weight; }
            set { _weight = value; }
        }

        public int age
        {
            get { return _age; }
            set { _age = value; }
        }
    }
}
