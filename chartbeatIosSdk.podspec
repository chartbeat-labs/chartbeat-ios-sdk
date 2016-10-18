Pod::Spec.new do |s|
  s.name                    = "chartbeatIosSdk"
  s.version                 = "1.0"
  s.license                 = { :type => "MIT", :file => "LICENSE" }
  s.summary                 = "This is the Chartbeat iOS SDK -- providing a library for iOS applications so they can send tracking events to Chartbeat."
  s.homepage                = "https://chartbeat.com/"
  s.author                  = { "Chartbeat" => "support@chartbeat.com" }
  s.source                  = { :git => "https://github.com/GiarcEnoredlac/cbiossdk.git", :tag => "1.0" }

  s.platform                = :ios, '7.0'
  s.requires_arc            = true
  s.public_header_files     = "chartbeatIosSdk.framework/**/*.h"
  s.vendored_frameworks     = "chartbeatIosSdk.framework"
  s.frameworks              = 'SystemConfiguration', 'MediaPlayer'

  s.module_name             = 'chartbeatIosSdk'
end