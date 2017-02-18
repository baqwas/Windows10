#pragma once

#include "pch.h"

namespace BlinkyCPPHeadless
{
    [Windows::Foundation::Metadata::WebHostHidden]
    public ref class StartupTask sealed : public Windows::ApplicationModel::Background::IBackgroundTask
    {
    public:
		StartupTask();
        virtual void Run(Windows::ApplicationModel::Background::IBackgroundTaskInstance^ taskInstance);
	private:
		void InitGpio();
		Platform::Agile<Windows::ApplicationModel::Background::BackgroundTaskDeferral> Deferral;
		Windows::ApplicationModel::Background::IBackgroundTaskInstance^ TaskInstance;
		Windows::System::Threading::ThreadPoolTimer ^Timer;
		Windows::Devices::Gpio::GpioPinValue pinValue;
		const int pinLED = 26;
		Windows::Devices::Gpio::GpioPin ^pin;

    };
}
