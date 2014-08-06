/* Copyright(C) 2014 Sarandogou <https://github.com/sarandogou/webrtc-everywhere> */
#ifndef _WEBRTC_EVERYWHERE_NPAPI_MESSAGEEVENT_H_
#define _WEBRTC_EVERYWHERE_NPAPI_MESSAGEEVENT_H_

#include "../common/_Config.h"
#include "../common/_Common.h"
#include "../common/_AsyncEvent.h"

#include "npapi-includes.h"

class MessageEvent
	: public NPObject
	, public _AsyncEventRaiser
{
public:
	MessageEvent(NPP instance);
	virtual ~MessageEvent();

public:
	static NPObject* Allocate(NPP instance, NPClass* npclass);
	static void Deallocate(NPObject* obj);
	static bool HasMethod(NPObject* obj, NPIdentifier methodName);
	static bool InvokeDefault(NPObject* obj, const NPVariant* args,
		uint32_t argCount, NPVariant* result);
	static bool Invoke(NPObject* obj, NPIdentifier methodName,
		const NPVariant* args, uint32_t argCount,
		NPVariant* result);
	static bool HasProperty(NPObject* obj, NPIdentifier propertyName);
	static bool GetProperty(NPObject* obj, NPIdentifier propertyName,
		NPVariant* result);
	static bool SetProperty(NPObject *npobj, NPIdentifier name, const NPVariant *value);
	static bool RemoveProperty(NPObject *npobj, NPIdentifier name);
	static bool NPEnumeration(NPObject *npobj, NPIdentifier **value,
		uint32_t *count);
	static void Invalidate(NPObject *npobj);
	static bool Construct(NPObject *npobj, const NPVariant *args, uint32_t argCount, NPVariant *result);

	NPObjectImpl_CreateInstanceWithRef(MessageEvent);
	NPObjectImpl_NPObjectRelease(MessageEvent);
	NPObjectImpl_IsInstanceOf(MessageEvent);

	void SetEvent(cpp11::shared_ptr<_MessageEvent> & _event);
	cpp11::shared_ptr<_MessageEvent> GetEvent();

private:
	NPP m_npp;
	std::shared_ptr<_MessageEvent> m_Event;
	NPVariant m_data;
};

#endif /* _WEBRTC_EVERYWHERE_NPAPI_MESSAGEEVENT_H_ */
