package com.example.teacherasistant

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.widget.TextView
import androidx.navigation.NavController
import androidx.navigation.fragment.NavHostFragment
import com.example.teacherasistant.callback.FragmentCallback
import com.example.teacherasistant.viewmodels.MainViewModel

class MainActivity : AppCompatActivity(), FragmentCallback {
    private lateinit var _mainViewModel: MainViewModel
    private lateinit var _navHostController: NavController
    private lateinit var sectionTitleTextView: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        _mainViewModel = MainViewModel(baseContext)
        sectionTitleTextView = findViewById(R.id.fragmentTitleTextView)

        val navHostFragment =
            supportFragmentManager.findFragmentById(R.id.nav_host_fragment) as NavHostFragment

        _navHostController = navHostFragment.navController
    }

    override fun onFragmentChanged(text: String) {
        sectionTitleTextView.text = text
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        val inflater = menuInflater
        inflater.inflate(R.menu.options_menu, menu)

        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        if (item.itemId == R.id.options_menu_reset_button) {
            _navHostController.popBackStack(R.id.subjectListFragment, false)

            _mainViewModel.deleteAllMarks()
            _mainViewModel.deleteAllStudents()
            _mainViewModel.deleteAllSubjectsWithStudents()
            _mainViewModel.deleteAllSubjects()
        }

        return super.onOptionsItemSelected(item)
    }
}