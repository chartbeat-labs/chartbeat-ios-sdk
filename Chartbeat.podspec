Pod::Spec.new do |s|
  s.platform                = :ios, '12.0'
  s.ios.deployment_target   = '12.0'
  s.name                    = "Chartbeat"
  s.summary                 = "This is the Chartbeat iOS SDK -- providing a library for iOS applications so they can send tracking events to Chartbeat."
  s.requires_arc            = true

  s.version                 = "1.5.12"

  s.license                 = { :type => "MIT", :file => "LICENSE" }

  s.author                  = { "Chartbeat" => "support@chartbeat.com" }

  s.homepage                = "https://chartbeat.com/"

  s.vendored_frameworks     = "Chartbeat.xcframework"
  s.resource_bundles        = {'Chartbeat_Privacy' => ['PrivacyInfo.xcprivacy']}
  s.source                  = { :git => "https://github.com/chartbeat-labs/chartbeat-ios-sdk.git", :tag => "1.5.12" }

  s.frameworks              = 'SystemConfiguration', 'MediaPlayer'
  s.module_name             = 'Chartbeat'
end
