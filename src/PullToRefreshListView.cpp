/*
 * PullToRefreshListView.cpp
 *
 *  Created on: Jul 20, 2014
 *      Author: seungju
 */

/*
import com.handmark.pulltorefresh.library.internal.EmptyViewMethodAccessor;
import com.handmark.pulltorefresh.library.internal.LoadingLayout;
*/

class PullToRefreshListView : public PullToRefreshAdapterViewBase<ListView>
{
private:
	LoadingLayout mHeaderLoadingView;
	LoadingLayout mFooterLoadingView;
	FrameLayout mLvFooterLoadingFrame;
	bool mListViewExtrasEnabled;


protected:

	//refreshing 될때의 상태들에 대한 함수
	//@Override
	void onRefreshing(const bool doScroll) {
			/**
			 * If we're not showing the Refreshing view, or the list is empty, the
			 * the header/footer views won't show so we use the normal method.
			 *
			ListAdapter adapter = mRefreshableView.getAdapter();
			if (!mListViewExtrasEnabled || !getShowViewWhileRefreshing() || null == adapter || adapter.isEmpty()) {
				super.onRefreshing(doScroll);
				return;
			}

			super.onRefreshing(false);

			final LoadingLayout origLoadingView, listViewLoadingView, oppositeListViewLoadingView;
			final int selection, scrollToY;

			switch (getCurrentMode()) {
				case MANUAL_REFRESH_ONLY:
				case PULL_FROM_END:
					origLoadingView = getFooterLayout();
					listViewLoadingView = mFooterLoadingView;
					oppositeListViewLoadingView = mHeaderLoadingView;
					selection = mRefreshableView.getCount() - 1;
					scrollToY = getScrollY() - getFooterSize();
					break;
				case PULL_FROM_START:
				default:
					origLoadingView = getHeaderLayout();
					listViewLoadingView = mHeaderLoadingView;
					oppositeListViewLoadingView = mFooterLoadingView;
					selection = 0;
					scrollToY = getScrollY() + getHeaderSize();
					break;
			}

			// Hide our original Loading View
			origLoadingView.reset();
			origLoadingView.hideAllViews();

			// Make sure the opposite end is hidden too
			oppositeListViewLoadingView.setVisibility(View.GONE);

			// Show the ListView Loading View and set it to refresh.
			listViewLoadingView.setVisibility(View.VISIBLE);
			listViewLoadingView.refreshing();

			if (doScroll) {
				// We need to disable the automatic visibility changes for now
				disableLoadingLayoutVisibilityChanges();

				// We scroll slightly so that the ListView's header/footer is at the
				// same Y position as our normal header/footer
				setHeaderScroll(scrollToY);

				// Make sure the ListView is scrolled to show the loading
				// header/footer
				mRefreshableView.setSelection(selection);

				// Smooth scroll as normal
				smoothScrollTo(0);
			}
			*/
		}

	//
	//@Override
	void onReset() {
		/**
		 * If the extras are not enabled, just call up to super and return.
		 *
		if (!mListViewExtrasEnabled) {
			super.onReset();
			return;
		}

		final LoadingLayout originalLoadingLayout, listViewLoadingLayout;
		final int scrollToHeight, selection;
		final boolean scrollLvToEdge;

		switch (getCurrentMode()) {
			case MANUAL_REFRESH_ONLY:
			case PULL_FROM_END:
				originalLoadingLayout = getFooterLayout();
				listViewLoadingLayout = mFooterLoadingView;
				selection = mRefreshableView.getCount() - 1;
				scrollToHeight = getFooterSize();
				scrollLvToEdge = Math.abs(mRefreshableView.getLastVisiblePosition() - selection) <= 1;
				break;
			case PULL_FROM_START:
			default:
				originalLoadingLayout = getHeaderLayout();
				listViewLoadingLayout = mHeaderLoadingView;
				scrollToHeight = -getHeaderSize();
				selection = 0;
				scrollLvToEdge = Math.abs(mRefreshableView.getFirstVisiblePosition() - selection) <= 1;
				break;
		}

		// If the ListView header loading layout is showing, then we need to
		// flip so that the original one is showing instead
		if (listViewLoadingLayout.getVisibility() == View.VISIBLE) {

			// Set our Original View to Visible
			originalLoadingLayout.showInvisibleViews();

			// Hide the ListView Header/Footer
			listViewLoadingLayout.setVisibility(View.GONE);

			/**
			 * Scroll so the View is at the same Y as the ListView
			 * header/footer, but only scroll if: we've pulled to refresh, it's
			 * positioned correctly
			 *
			if (scrollLvToEdge && getState() != State.MANUAL_REFRESHING) {
				mRefreshableView.setSelection(selection);
				setHeaderScroll(scrollToHeight);
			}
		}

		// Finally, call up to super
		super.onReset();
		*/
	}

	//loadingLayoutProxy.cpp 의 함수 오버라이드 하는 함수
	//@Override
	LoadingLayoutProxy createLoadingLayoutProxy(const bool includeStart, const bool includeEnd) {
		/*
		LoadingLayoutProxy proxy = super.createLoadingLayoutProxy(includeStart, includeEnd);

		if (mListViewExtrasEnabled) {
			final Mode mode = getMode();

			if (includeStart && mode.showHeaderLoadingLayout()) {
				proxy.addLayout(mHeaderLoadingView);
			}
			if (includeEnd && mode.showFooterLoadingLayout()) {
				proxy.addLayout(mFooterLoadingView);
			}
		}

		return proxy;
		*/
	}

	//listview 만드는 함수
	//param: Context context, AttributeSet attrs
	ListView createListView() {
		/*
		final ListView lv;
		if (VERSION.SDK_INT >= VERSION_CODES.GINGERBREAD) {
			lv = new InternalListViewSDK9(context, attrs);
		} else {
			lv = new InternalListView(context, attrs);
		}
		return lv;
		*/
	}

	//refreshable view 만드는 함수
	//param:Context context, AttributeSet attrs
	//@Override
	ListView createRefreshableView() {
		/*
		ListView lv = createListView(context, attrs);

		// Set it to this so it can be used in ListActivity/ListFragment
		lv.setId(android.R.id.list);
		return lv;
		*/
	}

	//header / footer frame, view 설정하는 함수 인듯
	//param: TypedArray a
	//@Override
	void handleStyledAttributes() {
		/*
		super.handleStyledAttributes(a);

		mListViewExtrasEnabled = a.getBoolean(R.styleable.PullToRefresh_ptrListViewExtrasEnabled, true);

		if (mListViewExtrasEnabled) {
			final FrameLayout.LayoutParams lp = new FrameLayout.LayoutParams(FrameLayout.LayoutParams.MATCH_PARENT,
					FrameLayout.LayoutParams.WRAP_CONTENT, Gravity.CENTER_HORIZONTAL);

			// Create Loading Views ready for use later
			FrameLayout frame = new FrameLayout(getContext());
			mHeaderLoadingView = createLoadingLayout(getContext(), Mode.PULL_FROM_START, a);
			mHeaderLoadingView.setVisibility(View.GONE);
			frame.addView(mHeaderLoadingView, lp);
			mRefreshableView.addHeaderView(frame, null, false);

			mLvFooterLoadingFrame = new FrameLayout(getContext());
			mFooterLoadingView = createLoadingLayout(getContext(), Mode.PULL_FROM_END, a);
			mFooterLoadingView.setVisibility(View.GONE);
			mLvFooterLoadingFrame.addView(mFooterLoadingView, lp);

			/**
			 * If the value for Scrolling While Refreshing hasn't been
			 * explicitly set via XML, enable Scrolling While Refreshing.
			 *
			if (!a.hasValue(R.styleable.PullToRefresh_ptrScrollingWhileRefreshingEnabled)) {
				setScrollingWhileRefreshingEnabled(true);
			}
		}
	*/
	}

	//listview 내부 설정들 설정하는 함수 인듯

	class InternalListView : public EmptyViewMethodAccessor {
		/*private boolean mAddedLvFooter = false;

		public InternalListView(Context context, AttributeSet attrs) {
			super(context, attrs);
		}

		@Override
		protected void dispatchDraw(Canvas canvas) {
			/**
			 * This is a bit hacky, but Samsung's ListView has got a bug in it
			 * when using Header/Footer Views and the list is empty. This masks
			 * the issue so that it doesn't cause an FC. See Issue #66.
			 *
			try {
				super.dispatchDraw(canvas);
			} catch (IndexOutOfBoundsException e) {
				e.printStackTrace();
			}
		}

		@Override
		public boolean dispatchTouchEvent(MotionEvent ev) {
			/**
			 * This is a bit hacky, but Samsung's ListView has got a bug in it
			 * when using Header/Footer Views and the list is empty. This masks
			 * the issue so that it doesn't cause an FC. See Issue #66.
			 *
			try {
				return super.dispatchTouchEvent(ev);
			} catch (IndexOutOfBoundsException e) {
				e.printStackTrace();
				return false;
			}
		}

		@Override
		public void setAdapter(ListAdapter adapter) {
			// Add the Footer View at the last possible moment
			if (null != mLvFooterLoadingFrame && !mAddedLvFooter) {
				addFooterView(mLvFooterLoadingFrame, null, false);
				mAddedLvFooter = true;
			}

			super.setAdapter(adapter);
		}

		@Override
		public void setEmptyView(View emptyView) {
			PullToRefreshListView.this.setEmptyView(emptyView);
		}

		@Override
		public void setEmptyViewInternal(View emptyView) {
			super.setEmptyView(emptyView);
		}*/
	};

public:

	//생성자///////////////////////////////////////////////////////////
	PullToRefreshListView() {
		//super(context);
	}

	//param : Context, AttributeSet
	PullToRefreshListView() {
		//super(context, attrs);
	}

	//param: Context, Mode
	PullToRefreshListView() {
		//super(context, mode);
	}

	//param :Context context, Mode mode, AnimationStyle style
	PullToRefreshListView() {
		//super(context, mode, style);
	}

	//@override
	const Orientation getPullToRefreshScrollDirection() {
		//return Orientation.VERTICAL;
	}



};
