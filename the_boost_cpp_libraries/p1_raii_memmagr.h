#pragma once

#include <boost/shared_array.hpp>
#include <boost/scoped_array.hpp>

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/intrusive_ptr.hpp>

#include <boost/make_shared.hpp>

#include <functional>
#include <iostream>
#include <thread>

//https://theboostcpplibraries.com/raii-and-memory-management
namespace raii_mm
{
	// https://theboostcpplibraries.com/boost.smartpointers
	namespace smart_pointers
	{
		// Sole Ownership
		// https://theboostcpplibraries.com/boost.smartpointers-sole-ownership
		namespace sole_ownership
		{			
			void scoped_ptr()
			{
				std::cout << "scoped_ptr" << '\n';

				boost::scoped_ptr<int> p{ new int{ 1 } };
				std::cout << *p << '\n';
				std::cout << std::boolalpha << static_cast<bool>(p) << '\n';

				p.reset(new int{ 2 });
				std::cout << *p.get() << '\n';
				std::cout << std::boolalpha << static_cast<bool>(p) << '\n';

				p.reset();
				std::cout << std::boolalpha << static_cast<bool>(p) << '\n';

				std::cout << '\n';
			}

			void scoped_array()
			{
				std::cout << "scoped_array" << '\n';

				boost::scoped_array<int> p{ new int[2] };
				*p.get() = 1;

				std::cout << p[0] << '\n';
				std::cout << p[1] << '\n';

				p[1] = 2;

				std::cout << p[0] << '\n';
				std::cout << p[1] << '\n';

				p.reset(new int[3]);
				std::cout << p[0] << '\n';
				std::cout << p[1] << '\n';
				std::cout << p[2] << '\n';

				std::cout << '\n';
			}
		}
	
		// Shared Ownership
		// https://theboostcpplibraries.com/boost.smartpointers-shared-ownership
		namespace shared_ownership
		{
			void shared_ptr()
			{
				std::cout << "shared_ptr" << '\n';
				boost::shared_ptr<int> p1{new int{1}};
				std::cout << *p1 << '\n';

				boost::shared_ptr<int> p2{ p1 };
				std::cout << *p2 << '\n';

				p1.reset(new int{2});
				std::cout << *p1.get() << '\n';
				std::cout << *p2.get() << '\n';

				p1.reset();

				std::cout << std::boolalpha << static_cast<bool>(p1) << '\n';
				std::cout << std::boolalpha << static_cast<bool>(p2) << '\n';
				std::cout << '\n';
			}

			void custom_deleter()
			{
				// requires #include <Windows.h>
				/*
				 	boost::shared_ptr<void> handle{ OpenProcess(PROCESS_SET__INFORMATION, FALSE,
													GetCurrentProcessId()), CloseHandle); };
				*/
			}

			void make_shared()
			{
				std::cout << "make_shared" << '\n';
				
				auto p1 = boost::make_shared<int>(1);
				std::cout << typeid(p1).name() << '\n';

				auto p2 = boost::make_shared<int[]>(10);
				std::cout << typeid(p2).name() << '\n';
			}

			void shared_array()
			{
				std::cout << "shared_array" << '\n';

				boost::shared_array<int> p1{new int[1]};
				{
					boost::shared_array<int> p2{ p1 };
					p2[0] = 1;
				}

				std::cout << p1[0] << '\n';
			}

			// read up on  BOOST_SP_USE_QUICK_ALLOCATOR
			//#define BOOST_SP_USE_QUICK_ALLOCATOR
		}

		// Special Smart Pointers
		// https://theboostcpplibraries.com/boost.smartpointers-special-smart-pointers
		namespace special_smart_pointers
		{
			namespace weak
			{
				void reset(boost::shared_ptr<int>& sh)
				{
					sh.reset();
				}
				void print(boost::weak_ptr<int>& w)
				{
					boost::shared_ptr<int> sh = w.lock();
					if (sh)
						std::cout << *sh << '\n';
				}
				void weak_ptr()
				{
					boost::shared_ptr<int> sh{ new int{99} };
					boost::weak_ptr<int> w{ sh };

					std::thread t1{ reset, std::ref(sh) };
					std::thread t2{ print, std::ref(w) };

					t1.join();
					t2.join();
				}
			}
			namespace intrusive
			{

			}
		}
	}
}
