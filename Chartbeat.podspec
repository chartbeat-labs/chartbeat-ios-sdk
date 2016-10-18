Pod::Spec.new do |s|
  s.name                    = "Chartbeat"
  s.version                 = "1.1"
  s.license                 = { :type => "MIT", :file => "LICENSE" }
  s.summary                 = "This is the Chartbeat iOS SDK -- providing a library for iOS applications so they can send tracking events to Chartbeat."
  s.homepage                = "https://chartbeat.com/"
  s.author                  = { "Chartbeat" => "support@chartbeat.com" }
  s.source                  = { :git => "https://github.com/GiarcEnoredlac/cbiossdk.git", :tag => "1.1" }

  s.platform                = :ios, '8.0'
  s.requires_arc            = true
  s.public_header_files     = "Chartbeat.framework/**/*.h"
  s.vendored_frameworks     = "Chartbeat.framework"
  s.frameworks              = 'SystemConfiguration', 'MediaPlayer'

  s.module_name             = 'Chartbeat'
end