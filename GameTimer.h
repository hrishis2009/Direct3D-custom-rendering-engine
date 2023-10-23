#pragma once
#include <windows.h>

class GameTimer
{
public:
	GameTimer();
	~GameTimer();

	float DeltaTime() const
	{
		return static_cast<float>(mDeltaTime);
	};

	float TotalTime() const
	{
		if (mStopped)
		{
			return (float)((mStopTime - mPausedTime) - mBaseTime) * mSecondsPerFrame;
		}
		else
		{
			return (float)((mCurrTime - mPausedTime) - mBaseTime) * mSecondsPerFrame;
		}
	};

	void Reset();
	void Start();
	void Stop();
	void Increment();

private:
	double mSecondsPerFrame;
	double mDeltaTime;

	__int64 mBaseTime;
	__int64 mPausedTime;
	__int64 mStopTime;
	__int64 mPrevTime;
	__int64 mCurrTime;

	bool mStopped;
};