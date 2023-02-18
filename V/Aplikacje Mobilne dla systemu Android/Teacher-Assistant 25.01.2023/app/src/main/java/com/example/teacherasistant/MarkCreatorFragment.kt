package com.example.teacherasistant

import android.content.Context
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.AdapterView
import android.widget.ArrayAdapter
import android.widget.Button
import android.widget.EditText
import android.widget.RadioGroup
import android.widget.Spinner
import android.widget.Toast
import androidx.navigation.findNavController
import com.example.teacherasistant.database.entities.Mark
import com.example.teacherasistant.viewmodels.MarkCreatorViewModel

/**
 * A simple [Fragment] subclass.
 */
class MarkCreatorFragment : Fragment(), AdapterView.OnItemSelectedListener {
    private var _subjectId: Long? = null
    private var _studentId: Long? = null

    private lateinit var _markCreatorViewModel: MarkCreatorViewModel

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val args = arguments?.let {
            MarkCreatorFragmentArgs.fromBundle(it)
        }

        if (args != null) {
            _subjectId = args.subjectId
            _studentId = args.studentId
        }
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val view = inflater.inflate(R.layout.fragment_mark_creator, container, false)

        _markCreatorViewModel =
            MarkCreatorViewModel(activity as Context, _subjectId!!, _studentId!!)

        val pointsEditText: EditText = view.findViewById(R.id.mark_creator_points_edit_text)
        val gradeSpinner: Spinner = view.findViewById(R.id.mark_creator_grade_spinner)
        gradeSpinner.onItemSelectedListener = this

        ArrayAdapter.createFromResource(
            activity as Context,
            R.array.grades,
            R.layout.my_spinner_item
        ).also { adapter ->
            adapter.setDropDownViewResource(R.layout.my_dropdown_spinner_item)
            gradeSpinner.adapter = adapter
        }

        val modeRadioGroup: RadioGroup = view.findViewById(R.id.mode_radio_group)
        modeRadioGroup.setOnCheckedChangeListener { _, id ->
            when (id) {
                R.id.grade_mode_radio_button -> {
                    gradeSpinner.visibility = View.VISIBLE
                    pointsEditText.visibility = View.GONE
                }

                else -> {
                    pointsEditText.visibility = View.VISIBLE
                    gradeSpinner.visibility = View.GONE
                }
            }
        }

        val createMarkButton: Button = view.findViewById(R.id.mark_creator_create_button)
        createMarkButton.setOnClickListener {
            val mark: Mark

            when (modeRadioGroup.checkedRadioButtonId) {
                R.id.grade_mode_radio_button -> {
                    mark = Mark(null, _studentId, _subjectId, gradeSpinner.selectedItem.toString())
                    _markCreatorViewModel.insertMark(mark)
                    view.findNavController().popBackStack()
                }

                R.id.points_mode_radio_button -> {
                    mark = Mark(null, _studentId, _subjectId, pointsEditText.text.toString())
                    _markCreatorViewModel.insertMark(mark)
                    view.findNavController().popBackStack()
                }

                else -> {
                    Toast.makeText(context, "Nie wybrano typu!", Toast.LENGTH_SHORT).show()
                }
            }
        }

        return view
    }

    override fun onItemSelected(parent: AdapterView<*>, view: View?, pos: Int, id: Long) {
        // An item was selected. You can retrieve the selected item using
        // parent.getItemAtPosition(pos)
    }

    override fun onNothingSelected(parent: AdapterView<*>) {
        // Another interface callback
    }
}