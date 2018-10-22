#if defined _easy_keys_included
	#endinput
#endif
#define _easy_keys_included

#include <a_samp>

#if !defined KEY_AIM
	#define KEY_AIM		KEY_HANDBRAKE
#endif
#if !defined HOLDING
	#define HOLDING(%0)		((newkeys & (%0)) == (%0))
#endif
#if !defined PRESSED
	#define PRESSED(%0)		(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#endif
#if !defined RELEASED
	#define RELEASED(%0)	(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))
#endif

forward OnPlayerClickY(playerid);
forward OnPlayerClickN(playerid);
forward OnPlayerClickH(playerid);
forward OnPlayerClickAlt(playerid);
forward OnPlayerClickEnter(playerid);
forward OnPlayerClickSprint(playerid);
forward OnPlayerClickSubmission(playerid);

public	OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (PRESSED(KEY_YES))
	{
		return CallLocalFunction("OnPlayerClickY", "d", playerid);
	}
	else if (PRESSED(KEY_NO))
	{
		return CallLocalFunction("OnPlayerClickN", "d", playerid);
	}
	else if (PRESSED(KEY_CTRL_BACK))
	{
		return CallLocalFunction("OnPlayerClickH", "d", playerid);
	}
	else if (PRESSED(KEY_WALK))
    {
    	return CallLocalFunction("OnPlayerClickAlt", "d", playerid);
    }
	else if (PRESSED(KEY_SECONDARY_ATTACK))
    {
    	return CallLocalFunction("OnPlayerClickEnter", "d", playerid);
    }
	else if (PRESSED(KEY_SPRINT))
	{
		return CallLocalFunction("OnPlayerClickSprint", "d", playerid);
	}
	else if(PRESSED(KEY_SUBMISSION))
	{
		return CallLocalFunction("OnPlayerClickSubmission", "d", playerid);
	}

	#if defined EasyKeys_OnPlayerKeyStateChange
		return (EasyKeys_OnPlayerKeyStateChange(playerid, newkeys, oldkeys));
	#else
		return (1);
	#endif
}
#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange	EasyKeys_OnPlayerKeyStateChange
#if defined EasyKeys_OnPlayerKeyStateChange
	forward EasyKeys_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif