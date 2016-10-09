# cbiossdk
for cocoapods implementation
<title>INSTRUCTIONS</title></head><body><article class="markdown-body"><h1>
<a id="user-content-introduction" class="anchor" href="#introduction" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>Introduction</h1>

<p>Chartbeat’s Native Mobile SDKs integrate Chartbeat analytics tracking with your native iOS or Android app.</p>

<p>If instead of a native mobile app you have a web app (or if you have a native app that is a thin wrapper around a mobile website that can run javascript in the webviews), please <a href="http://support.chartbeat.com/docs/integrations.html#app">visit this page for further instructions</a>.</p>

<p>Once you integrate the SDK into your app, a new field will appear under the Distribution section on the left-hand side of your Chartbeat Publishing Dashboard, called "App." This will display the percentage of concurrents that are engaging with your native app content.</p>

<p>Additionally, by selecting the app distribution channel you'll filter the entire Dashboard to only show you the concurrents who are engaging with your app content, as well as all the Chartbeat metrics specific to that group.</p>

<h1>
<a id="user-content-preflight-and-overview-of-settings" class="anchor" href="#preflight-and-overview-of-settings" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>Preflight and Overview of Settings</h1>

<p>If you're interested in integrating Chartbeat into your native app to track real-time data on those readers, first be sure you’ve completed these prerequisites before moving forward:
You must be a current Chartbeat Publishing client with Chartbeat code already successfully implemented on your website.</p>

<p>You'll set the Chartbeat Account ID and the <code>domain</code> once when you initialize the Tracker SDK, as these settings will not change from article to article.</p>

<h4>
<a id="user-content-account-id" class="anchor" href="#account-id" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>Account ID</h4>

<p>If you don't know your Chartbeat Account ID (also known as your "UID"), head over to <a href="https://chartbeat.com/publishing/setup/code">chart.bt/setup</a>, enter the domain you're tracking into the field and select "generate code." In the generated code block, there will be a line that sets <code>_sf_async_config.uid</code> — that number is your Chartbeat Account ID.</p>

<h4>
<a id="user-content-domain" class="anchor" href="#domain" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>Domain</h4>

<p>We recommend that you set the <code>domain</code> setting to match the <code>_sf_async_config.domain</code> setting from your Chartbeat Publishing (website) setup; this will send all of your native app traffic data to the same dashboard as your website traffic. This is normally the actual domain of your website (without any "<a href="http://www.">www.</a>" at the front of it). For example, this might be something like "mynewssite.com".</p>

<p>If you <em>don't</em> want you native app traffic to roll up with your website traffic, you can set the <code>domain</code> setting in the SDK to some subdomain of your website top-level domain (this does not have to actually exist as a website, but you should own the top-level domain to ensure you choose a globally unique name). For instance, you may choose <code>nativeapp.mynewssite.com</code>.</p>

<h4>
<a id="user-content-views-vs-pages" class="anchor" href="#views-vs-pages" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>Views vs. Pages</h4>

<p>In your mobile app you'll be tracking "views" (screens of content) instead of how we track "pages" on the web. In tracking each view of the app, you have two options:</p>

<ol>
<li>If you want your native app traffic to roll up with the traffic from the corresponding page on your website, you will need to set the <code>viewId</code> to the same string path that the corresponding page reports to from your website. For instance, if you implemented canonical URL’s for your website, your article may report with the <code>path</code> set to <code>/sports/what-defines-me-ryan-lochte</code>. For native app traffic for that article to rollup correctly in the dashboard with the website traffic, when you call <code>trackView</code> in the mobile SDK, you would set the <code>viewId</code> parameter to <code>/sports/what-defines-me-ryan-lochte</code> so it matches.</li>
<li>If instead you’d like to track your app traffic as separate "pages" from your web traffic in your dashboard, you can set the <code>viewId</code> to some identifier which will not collide with any <code>path</code> reported by your website. For instance, you might want to set the <code>viewId</code> to something like <code>/nativeapp/sports/what-defines-me-ryan-lochte</code> — the <code>/nativeapp</code> prefix there will keep this traffic separate from the website page for the same article.</li>
</ol>

<p>If a view (any "place" the user can be in your app) doesn't correspond to a page on your website, you can still track the user on that screen. Just choose an identifier (as in the second scenario above) that will not collide with any page path from your website, and the traffic will be tracked to a separate "page" in your dashboard. For instance, you could track users in the "table of contents" screen of your app to a <code>viewId</code> like <code>/nativeapp/main-toc</code>.</p>

<p>Our general recommendation is to track users through all views/screens of your app. After initializing the tracker, you just call <code>trackView</code> (preceded by <code>setSections</code> and <code>setAuthors</code>) each time the user navigates to a new screen.</p>

<h4>
<a id="user-content-example-scenario" class="anchor" href="#example-scenario" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>Example Scenario:</h4>

<ol>
<li>User opens the app and lands on the default view (maybe a home view or table of contents), call <code>trackView</code> to track that the user is there.</li>
<li>User then selects an article to go to — call <code>trackView</code> to track that the user went there (using the article path from your website as the <code>viewId</code> if you want the traffic to rollup with your website traffic in your dashboard).</li>
<li>User navigates to a related article — call <code>trackView</code> for the new article.</li>
<li>User closes article, going back to the table of contents — call <code>trackView</code> once again to track that the user is on the TOC again.</li>
</ol>

<h4>
<a id="user-content-sections-and-authors" class="anchor" href="#sections-and-authors" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>Sections and Authors</h4>

<p>In addition to <code>viewId</code> and <code>title</code>, you can set section and author data (an array of strings for each) for each view you track. To do so, call <code>setSections</code> and <code>setAuthors</code> immediately before calling <code>trackView</code> each time. If you are doing this, it's important to <em>always</em> do this, as any sections and authors you set will stay set until you set a different set of values, which may be unexpected as you track multiple views. For instance, in the above Example Scenario, each time we said "call <code>trackView</code>," you would actually call <code>setAuthors</code>, then <code>setSections</code>, then <code>trackView</code>.</p>

<h1>
<a id="user-content-chartbeat-ios-sdk" class="anchor" href="#chartbeat-ios-sdk" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>Chartbeat iOS SDK</h1>

<h3>
<a id="user-content-setup" class="anchor" href="#setup" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>Setup</h3>

<p>Drag the framework file into your project.</p>

<p>If you're using the Chartbeat tracker in a Swift project, please first create a "bridging header." For details on how to create a bridging header, please refer to <a href="https://developer.apple.com/library/ios/documentation/Swift/Conceptual/BuildingCocoaApps/MixandMatch.html">this Apple Document</a>.</p>

<p>Inside the bridging header, import the <code>CBTracker.h</code> header file:</p>

<pre><code>#import "CBTracker.h"
</code></pre>

<h3>
<a id="user-content-1-initialize-the-tracker" class="anchor" href="#1-initialize-the-tracker" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>1. Initialize the Tracker</h3>

<p>Initialize the tracker by calling the <code>setupTrackerWithAccountID:domain</code> method on the tracker singleton obtained via <code>[CBTracker sharedTracker]</code>. It is often convenient to call this method directly in the <code>applicationDidBecomeActive</code> method of your app delegate.</p>

<div class="highlight highlight-source-objc"><pre><span class="pl-c">// Example using account id 1234 for domain "yoursite.com"</span>

<span class="pl-c">// Objective-C</span>

#<span class="pl-k">import</span> <span class="pl-s"><span class="pl-pds">&lt;</span>Chartbeat/CBTracker.h<span class="pl-pds">&gt;</span></span>

[[CBTracker <span class="pl-c1">sharedTracker</span>] <span class="pl-c1">setupTrackerWithAccountId:</span><span class="pl-c1">1234</span> <span class="pl-c1">domain:</span><span class="pl-s"><span class="pl-pds">@"</span>mydomain.com<span class="pl-pds">"</span></span> ]</pre></div>

<div class="highlight highlight-source-swift"><pre><span class="pl-c">// Swift</span>

CBTracker<span class="pl-k">.</span>sharedTracker()<span class="pl-k">.</span>setupTrackerWithAccountId(<span class="pl-c1">1234</span>, domain:<span class="pl-s"><span class="pl-pds">"</span>yoursite.com<span class="pl-pds">"</span></span>);</pre></div>

<p>See the <a href="#preflight-and-overview-of-settings">preflight section</a> at the top of this document for details on how to determine what values you should use for <code>accountId</code> and <code>domain</code>.</p>

<h3>
<a id="user-content-2-tracking-each-view" class="anchor" href="#2-tracking-each-view" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>2. Tracking each View</h3>

<p>To track a view, your view controller should import <code>CBTracker.h</code>, and then in <code>viewDidAppear</code>:</p>

<ul>
<li>Call <code>setSections</code> and <code>setAuthors</code> to set the section and author metadata to report with this view. If a view does not have section or author metadata associated with it, pass an empty array.</li>
<li>Call <code>trackView</code>. See the <a href="#views-vs-pages">Views vs. Pages section above</a> for more detail on what values to pass to <code>trackView</code>.</li>
</ul>

<div class="highlight highlight-source-objc"><pre><span class="pl-c">// Example tracking a view. Set author and section metadata, then trackView</span>

<span class="pl-c">// Objective-C</span>

#<span class="pl-k">import</span> <span class="pl-s"><span class="pl-pds">&lt;</span>Chartbeat/CBTracker.h<span class="pl-pds">&gt;</span></span>

[[CBTracker <span class="pl-c1">sharedTracker</span>] <span class="pl-c1">setAuthors:</span>@[<span class="pl-s"><span class="pl-pds">@"</span>John Smith<span class="pl-pds">"</span></span>, <span class="pl-s"><span class="pl-pds">@"</span>Jane Doe<span class="pl-pds">"</span></span>]];
[[CBTracker <span class="pl-c1">sharedTracker</span>] <span class="pl-c1">setSections:</span>@[<span class="pl-s"><span class="pl-pds">@"</span>news<span class="pl-pds">"</span></span>, <span class="pl-s"><span class="pl-pds">@"</span>tech<span class="pl-pds">"</span></span>]];
[[CBTracker <span class="pl-c1">sharedTracker</span>] <span class="pl-c1">trackView:</span><span class="pl-v">self</span>.view
    <span class="pl-c1">viewId:</span><span class="pl-s"><span class="pl-pds">@"</span>/article/date/brand-new-driverless-cars<span class="pl-pds">"</span></span>
    <span class="pl-c1">title:</span><span class="pl-s"><span class="pl-pds">@"</span>Driverless cars will overpower humanity<span class="pl-pds">"</span></span>];</pre></div>

<div class="highlight highlight-source-swift"><pre><span class="pl-c">// Swift</span>

CBTracker<span class="pl-k">.</span>sharedTracker()<span class="pl-k">.</span>authors <span class="pl-k">=</span> [<span class="pl-s"><span class="pl-pds">"</span>John Smith<span class="pl-pds">"</span></span>, <span class="pl-s"><span class="pl-pds">"</span>Jane Doe<span class="pl-pds">"</span></span>];
CBTracker<span class="pl-k">.</span>sharedTracker()<span class="pl-k">.</span>sections <span class="pl-k">=</span> [<span class="pl-s"><span class="pl-pds">"</span>news<span class="pl-pds">"</span></span>, <span class="pl-s"><span class="pl-pds">"</span>tech<span class="pl-pds">"</span></span>];
CBTracker<span class="pl-k">.</span>sharedTracker()<span class="pl-k">.</span>trackView(<span class="pl-k">self</span><span class="pl-k">.</span>view,
    viewId: <span class="pl-s"><span class="pl-pds">"</span>/article/date/brand-new-driverless-cars<span class="pl-pds">"</span></span>,
    title: <span class="pl-s"><span class="pl-pds">"</span>Driverless cars will overpower humanity<span class="pl-pds">"</span></span>);</pre></div>

<h3>
<a id="user-content-3-debug-mode" class="anchor" href="#3-debug-mode" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>3. Debug Mode</h3>

<p>To help with integration and make sure the tracker is working properly, you can enable the debug mode of the tracker. When debug mode is turned on, exceptions will be thrown when the tracker is not started properly. You can also switch between logging tiers to see output from the tracker to help you with integration. When you are ready to submit the app, please turn debug mode off.</p>

<p>To use debug mode:</p>

<div class="highlight highlight-source-objc"><pre><span class="pl-c">// Do this before you call startTrackerWithAccountID</span>

<span class="pl-c">// Objective-C</span>

[[CBTracker <span class="pl-c1">sharedTracker</span>] <span class="pl-c1">setDebugMode:</span><span class="pl-c1">true</span>];
<span class="pl-c">// See CBTracker.h for other possible loglevels...</span>
[[CBTracker <span class="pl-c1">sharedTracker</span>] <span class="pl-c1">setLogLevel:</span>CBTrackerLogLevelVerbose];</pre></div>

<div class="highlight highlight-source-swift"><pre><span class="pl-c">// Swift</span>

CBTracker<span class="pl-k">.</span>sharedTracker()<span class="pl-k">.</span>debugMode <span class="pl-k">=</span> <span class="pl-c1">true</span>
CBTracker<span class="pl-k">.</span>sharedTracker()<span class="pl-k">.</span>logLevel <span class="pl-k">=</span> <span class="pl-k">.</span>Verbose</pre></div>

<p>All log output has the format <code>[CB]: xxxx</code></p>

<h3>
<a id="user-content-4-stoptracker---advancedrare-usage" class="anchor" href="#4-stoptracker---advancedrare-usage" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>4. stopTracker - Advanced/Rare Usage</h3>

<p>To temporarily pause tracking, for instance, if a user gets to a view that you absolutely don’t want to track, call the <code>stopTracker</code> method. To resume after a <code>stopTracker</code> call, call <code>trackView</code> again when the user returns to a view you want to track. You normally will not need to do this, and can just call <code>trackView</code> as you navigate to each new view, which the tracker will correctly interpret as movement from the previously-tracking view to the new view.</p>

<h3>
<a id="user-content-troubleshooting" class="anchor" href="#troubleshooting" aria-hidden="true"><span aria-hidden="true" class="octicon octicon-link"></span></a>Troubleshooting</h3>

<p>If you've implemented the Chartbeat SDK code and you're still seeing an error, we'd love to help troubleshoot.
So that we can best help you, send us an email at <a href="mailto:support@chartbeat.com">support@chartbeat.com</a> with:
your account information (including UID)
a description of the problem you're seeing</p>

<p>Our Chartcorps support team will dig into the code and help uncover the problem.</p>
</article>
