#include "OgreSocksTCPClient.h"
#include "MogreSocksTCP.h"
#include "Util.h"

using namespace OgreSocks;
using namespace System;

namespace MogreSocks
{
	public ref class MogreSocksTCPClient : MogreSocksTCP
	{
	private:
		OgreSocksTCPClient* _nativePtr;

	public:
		MogreSocksTCPClient(OgreSocksTCPClient* _nativePtr)
		{
			this->_nativePtr = _nativePtr;
		}

		int Connect(String^ addr, unsigned long port)
		{
			Ogre::String saddr;
			Util::ConvertManagedStrToOgreStr(saddr, addr);
			return _nativePtr->Connect(saddr, port);
		}

		virtual void Send(array<System::Byte>^ data, String^ addr, unsigned long port) override
		{
			std::list<char> cdata = Util::ConvertByteArrayToListChar(data);

			Ogre::String saddr;
			Util::ConvertManagedStrToOgreStr(saddr, addr);

			_nativePtr->Send(cdata, saddr, port);
		}

		OgreSocksTCPClient* GetNativePtr()
		{
			return _nativePtr;
		}
	};
}